//
//  main.cpp
//  OperatorOverloading1
//
//  Created by abbas raza on 12/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of operator overloading.
 - Unary operator overloading (++, --). prefix and postfix('int' used to tell compiler. Not an argument.).
 - Functions that differ only in their return type cannot be overloaded.
 - Aliases (references) and pointers. int& alias = *ptr;
 - Returning reference to original object from a function.
 - Reference don't change once initialized. Unlike pointers which can be re-pointed to something different.
 - Here prefix and postfix doesn't make much difference. like we can't differentiate between postfix and prefix.
   However if we return a copy instead of alias of original object, then we can see difference. Because
	return Counter(count++); ---> new object will be returned with old counter value.
	is different from
	return Counter(++count); ---> new object will be returned with increamented counter value.
*/

#include <iostream>

class Counter
{
private:
	int count;
public:
	Counter():count(0)
	{
		
	}

	Counter(int c) : count(c)
	{
		
	}

	int get_count()
	{
		return count;
	}

	Counter& operator ++ ()
	{
		//std::cout << "overloaded operator called" << std::endl;
		++count;
		return *this;
	}
	Counter& operator ++ (int) // here int means postfix. Its not argument but to tell compiler that its postfix operator.
	{
		//std::cout << "overloaded operator called" << std::endl;
		count++;
		return *this;
	}
	
	Counter& operator -- ()
	{
		//std::cout << "overloaded operator called" << std::endl;
		--count;
		return *this;
	}
	Counter& operator -- (int) // here int means postfix. Its not argument but to tell compiler that its postfix operator.
	{
		//std::cout << "overloaded operator called" << std::endl;
		count--;
		return *this;
	}

	/* Another way to return temporary object
	 Counter operator ++ (int)
	 {
		std::cout << "overloaded operator called" << std::endl;
		return Counter(count++);
	 }
	*/
	
};

int main(int argc, const char * argv[])
{
	int a = 10;
	int * ptr = &a;
	int& b = *ptr;
	int * ptr2 = &(*ptr);

	std::cout << "Expecting Address of (a = b) = (stored in ptr and ptr2)" << std::endl;
	std::cout << "Address of a" << &a << std::endl;
	std::cout << "Address of b" << &b << std::endl;
	std::cout << "inside ptr " << ptr << std::endl;
	std::cout << "inside ptr2 " << ptr2 << std::endl;

	Counter c1;

	//c1++; //fails if there is not operator ++ (int)

	++c1; // c1 = 1;

	Counter& c2 = ++c1; // c1 = c2 = 2;
	
	std::cout << "Expecting Address of (c1 = c2)" << std::endl;
	std::cout << "Address of c1 " << &c1 << std::endl;
	std::cout << "Address of c2 " << &c2 << std::endl;

	std::cout << "Expecting c1 = c2 = 2;" << std::endl;
	std::cout << "c1 = " << c1.get_count() << std::endl;
	std::cout << "c2 = " << c2.get_count() << std::endl;

	++c2;
	std::cout << "Expecting c1 = c2 = 3;" << std::endl;
	std::cout << "c1 = " << c1.get_count() << std::endl;
	std::cout << "c2 = " << c2.get_count() << std::endl;

	Counter& c3 = c1++;
	std::cout << "Expecting c1 = c2 = c3 = 4;" << std::endl;
	std::cout << "c1 = " << c1.get_count() << std::endl;
	std::cout << "c2 = " << c2.get_count() << std::endl;
	std::cout << "c3 = " << c3.get_count() << std::endl;

	Counter c4 = ++c3;
	std::cout << "Expecting c1 = c2 = c3 = 5; c4 = 5;" << std::endl;
	std::cout << "c1 = " << c1.get_count() << std::endl;
	std::cout << "c2 = " << c2.get_count() << std::endl;
	std::cout << "c3 = " << c3.get_count() << std::endl;
	std::cout << "c4 = " << c4.get_count() << std::endl;

	++c4;
	std::cout << "Expecting c1 = c2 = c3 = 5; c4 = 6;" << std::endl;
	std::cout << "c1 = " << c1.get_count() << std::endl;
	std::cout << "c2 = " << c2.get_count() << std::endl;
	std::cout << "c3 = " << c3.get_count() << std::endl;
	std::cout << "c4 = " << c4.get_count() << std::endl;

	c3 = c4; // c1,c2,c3 will be changed.

	std::cout << "Expecting c1 = c2 = c3 = c4 = 6;" << std::endl;
	std::cout << "c1 = " << c1.get_count() << std::endl;
	std::cout << "c2 = " << c2.get_count() << std::endl;
	std::cout << "c3 = " << c3.get_count() << std::endl;
	std::cout << "c4 = " << c4.get_count() << std::endl;

	std::cout << "Expecting Address of (c1 = c2 = c3) != c4;" << std::endl;
	std::cout << "Address of c1 " << &c1 << std::endl;
	std::cout << "Address of c2 " << &c2 << std::endl;
	std::cout << "Address of c3 " << &c3 << std::endl;
	std::cout << "Address of c4 " << &c4 << std::endl;
	
	return 0;
}
