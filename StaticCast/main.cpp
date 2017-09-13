//
//  main.cpp
//  StaticCast
//
//  Created by abbas raza on 23/08/2017.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
	
	bool b = 42; // b is true
	int i = b;  // i = 1;
	i = 3.14; // i = 3
	double pi = i; // pi = 3.0
	unsigned char c = -1; // assuming 8-bit chars, c has value 255
	signed char v = 256; // v is 0
	
	
	
	/* When signed and unsigned operands are mixed */
	unsigned int v1 = 10;
	int v2 = -42;
	std::cout << v2 + v2 << std::endl; // prints -84
	
	/* the size of unsigned operand type is >= to the signed operand type i.e 32 bit
	   therefore, the signed operand is converted to unsigned operand first */
	std::cout << v2 + v1 << std::endl; // if 32-bit ints, prints 4294967264

	
	int u4 = -1;
	unsigned int u5 = 1;
	unsigned int u6 = u4 * u5; // signed converted to unsigned
	std::cout << "u6: " << u6 << std::endl;
	
	unsigned int u1 = 42, u2 = 10;
	int u3 = u2 - u1; // never mix signed and unsigned
	std::cout << u1 - u2 << std::endl; // ok: result is 32
	std::cout << u2 - u1 << std::endl; // ok: but the result will wrap around
	std::cout << u3 << std::endl; // ok: but the result will wrap around

	unsigned char vv1 = 2;
	int vv2 = -4;
	int r3 = vv2 * vv1;
	unsigned int r4 = vv2 * vv1;
	
	std::cout << "r3=" << r3 << std::endl;
	std::cout << "r4=" << r4 << std::endl;

	float f1 = 13/2; //implicit conversion--> result will be converted to float
	std::cout << "f1=" << f1 << std::endl; // f1 = 6
	
	
	float f2 = static_cast<float>(13)/2; //explicit conversion--> convert one operand to float, other will be automatically
										// converted. This way we can perform floating point division.
	std::cout << "f2=" << f2 << std::endl; //  f2 = 6.5
	
	
	int ci = 4;
	const int * ptrci = &ci;
	//int * ptrci2 = ptrci; //error. const to non constant conversions
	
	void * ptrvoid = &ci;
	int * ptrint = static_cast<int *>(ptrvoid);
	// int * ptrint = ptrvoid; // compiler error
	//int * ptrint2 = (int *)ptrvoid; // C-Style type conversion
	

	
	int intVar = 1500000000;
	std::cout << "int to signed short " << static_cast<signed short>(intVar) << std::endl;
	intVar = (intVar * 10) / 10;
	std::cout << "intVar = " << intVar << std::endl;
	intVar = 1500000000;
	intVar = (static_cast<double>(intVar) * 10) / 10;
	std::cout << "intVar = " << intVar << std::endl;   //right answer
	return 0;
}
