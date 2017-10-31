//
//  main.cpp
//  StaticCast
//
//  Created by abbas raza on 23/08/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - when and how to use static cast.
 - http://en.cppreference.com/w/cpp/language/static_cast
 - When:
	1) in standard Implicit conversions. Done by compiler automatically.
	2) in Explicit conversion between artihmetic types. (calculation involved)
	3) reverse of standard implicit conversions.
		int i;
		void * ptr = &f; // standard implicit conversion
		int * ptr = static_cast<int*>(ptr); // reverse of standard implicit conversion
	4) Templates: overloaded functions.
	5) Inheritance: Unsafe conversion between derived classes.
		 struct P {
		 int m = 0;
			void hello() const {
				std::cout << "Hello world, this is P!\n";
			}
		 };
		 struct C : P {
			void hello() const {
			std::cout << "Hello world, this is C!\n";
			}
		 };

		 // static downcast
		 C c;
		 P& pr = c; // upcast via implicit conversion
		 pr.hello();
		 C& another_c = static_cast<C&>(pr); // downcast
		 another_c.hello();
 
		 Hello world, this is P!
		 Hello world, this is C!


		***Assume**** that the P* points to a P that is part of a C object; don't bother performing a check. Adjust the address of the pointer if necessary so that it will point to the C object.
 - https://www.quora.com/How-do-you-explain-the-differences-among-static_cast-reinterpret_cast-const_cast-and-dynamic_cast-to-a-new-C++-programmer
 
*/

#include <iostream>

class P
{
public:
	int m;
	P():m(7)
	{
	}
	void hello() const
	{
		std::cout << "Hello world, this is P!\n";
	}
};

class C : public P
{
public:
	void hello() const
	{
		std::cout << "Hello world, this is C!\n";
	}
};

int main(int argc, const char * argv[])
{

	/* integer is converted to float
		integer / integer = integer. then integer is being converted to float.
		Both assignments are equal. 1st is implicit and 2nd is explicit casting.
		compiler uses static_cast in implicit conversion
	*/
	float f1 = 13/2;
	float f2 = static_cast<float>(13/2);
	std::cout << "f1=" << f1 << std::endl; // f1 = 6
	std::cout << "f2=" << f2 << std::endl; // f2 = 6
	
	/* To avoid tuncation, we should perform division in float.
	   For that, one of the operand should be in float.
	   so float/int = float
	*/
	float f3 = static_cast<float>(13)/2;
	std::cout << "f3=" << f3 << std::endl; // f3 = 6.5xxx


	/* double is converted to int
		double has a different representation in binary. so conversion is performed.
		Both assignments are equal. 1st is implicit and 2nd is explicit casting.
	*/
	int v1 = 3.8;
	int v2 = static_cast<int>(3.8);
	std::cout << "v1=" << v1 << std::endl;
	std::cout << "v2=" << v2 << std::endl;

	
	/* To prevent integer overflows */

	// Overflow:
	int v3 = 1500000000;
	v3 = (v3 * 10) / 10;
	std::cout << "v3 before cast = " << v3 << std::endl;

	// try again. convert one operand to type larger than int. i.e long. so all operands will be converted to long and operation will be performed in long without overflow. then long will be converted to int.
	v3 = 1500000000;
	/* Again need explicit conversion to shutup compiler */
	v3 = ((static_cast<long>(v3) * 10) / 10); // compiler warning that we are converting long to int.

	// again. to rectify compiler warning
	v3 = 1500000000;
	/* Hey compiler I know what i am doing, shutup */
	v3 = static_cast<int>((static_cast<long>(v3) * 10) / 10);

	std::cout << "v3 after cast = " << v3 << std::endl;

	std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
	std::cout << "sizeof(long) = " << sizeof(long) << std::endl;
	std::cout << "sizeof(long int) = " << sizeof(long int) << std::endl;
	std::cout << "sizeof(long long) = " << sizeof(long long) << std::endl;
	std::cout << "sizeof(long long int) = " << sizeof(long long int) << std::endl;


	/* void ptr to any type */
	void * ptr1 = &v3;
	int * pv1 = static_cast<int *>(ptr1);
	
	/* Inheritance:
	   upcast done implicitly.
	   downcast done explicitly. (unsafely using static_cast)
	*/
	
	/* Unsafe parent to child conversion (downcast):
	 static_cast assumes that the P* points to a P that is part of a C object;
	 don't bother performing a check. Adjust the address of the pointer if necessary
	 so that it will point to the C object.
	*/

	P p1;
	//C * c1 = &p1; // it will error.
	//C * c1 = (C *)&p1; // C-Style cast
	C * c1 = static_cast<C*>(&p1);
	c1->hello();

	/**** Child to parent conversion (upcast) is done implicitly ****/
	C c2; // ctor of C called and then ctor of P called. m created on stack.
	P * p2 = &c2; // upcast via implicit conversion. this is basically pointer to m.
	//P * p2 = static_cast<P*>(&c2); // ^^^ above statement is equal to this.
	p2->hello();

	C * c3 = static_cast<C *>(p2); // downcast
	
	/*
	 (lldb) print c3
	 (C *) $0 = 0x00007ffeefbff688
	 (lldb) print p2
	 (P *) $1 = 0x00007ffeefbff688
	 
	 x 0x00007ffeefbff688
	 0x7ffeefbff688: 07 00 00 00 00 00 00 00
	 */
	c3->hello();
	

	/* Templates: overloaded functions */
	// TODO
	return 0;
}
