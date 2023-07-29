//
//  main.cpp
//  ArithmeticConversions
//
//  Created by abbas raza on 12/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
	- ****** Arithmetic conversions and integral promotions : *******
	The purpose is to yield a common type, which is also the type of the result.
	--> https://stackoverflow.com/questions/5563000/implicit-type-conversion-rules-in-c-operators
	--> c++ standards document.

	Many binary operators that expect operands of arithmetic or enumeration type
	cause conversions and yield result types in a similar way. The purpose is to
	yield a common type, which is also the type of the result. This pattern is called
	the usual arithmetic conversions, which are defined as follows:
 
	— If either operand is of scoped enumeration type (7.2), no conversions are performed; 
	  if the other operand does not have the same type, the expression is ill-formed.

	— If either operand is of type long double, the other shall be converted to long double.
	— Otherwise, if either operand is double, the other shall be converted to double.
	— Otherwise, if either operand is float, the other shall be converted to float.
	— Otherwise, the integral promotions (4.5) shall be performed on both operands. 
		********************* integral promotions: ***********************
		Then the following rules shall be applied to the promoted operands:
		— If both operands have the same type, no further conversion is needed.
		— Otherwise, if both operands have signed integer types or both have unsigned integer 
		  types, the operand with the type of lesser integer conversion rank shall be converted to
		  the type of the operand with greater rank.
		— Otherwise, if the operand that has unsigned integer type has rank greater than or equal to
		  the rank of the type of the other operand, the operand with signed integer type shall be
		  converted to the type of the operand with unsigned integer type.
		— Otherwise, if the type of the operand with signed integer type can represent all of the values
		  of the type of the operand with unsigned integer type, the operand with unsigned integer type
		  shall be converted to the type of the operand with signed integer type.
		— Otherwise, both operands shall be converted to the unsigned integer type corresponding to the 
		  type of the operand with signed integer type.
 
		- Integer Conversion Rank:
		- No two signed integer types shall have the same rank, even if they have the same representation.
		- The rank of a signed integer type shall be greater than the rank of any signed integer type with
		  less precision.
		- The rank of long long int shall be greater than the rank of long int, which shall be greater than
		  the rank of int, which shall be greater than the rank of short int, which shall be greater than the
		  rank of signed char.
		- The rank of any unsigned integer type shall equal the rank of the corresponding signed integer type,
		  if any.
		- The rank of any standard integer type shall be greater than the rank of any extended integer type with
		  the same width.
		- The rank of char shall equal the rank of signed char and unsigned char.
		- The rank of any extended signed integer type relative to another extended signed integer type with the
		  same precision is implementation-defined but still subject to the other rules for determining the integer
		  conversion rank.
		- For all integer types T1, T2, and T3, if T1 has greater rank than T2 and T2 has greater rank than T3, 
		  then T1 has greater rank than T3.

 
	Note. The minimum size of operations is int. So short/char are promoted to int before the operation is done.
 
 
 Integer overflow
 ================
 
 Overflow is a phenomenon where operations on 2 numbers exceeds the maximum (or goes below the minimum) value the data type can have. Usually it is thought that integral types are very large and people don't take into account the fact that sum of two numbers can be larger than the range. But in things like scientific and mathematical computation, this can happen. For example, an unhandled arithmetic overflow in the engine steering software was the primary cause of the crash of the maiden flight of the Ariane 5 rocket. The software had been considered bug-free since it had been used in many previous flights; but those used smaller rockets which generated smaller accelerations than Ariane 5's.This article will tell how this problem can be tackled.
 
 In this article, we will only deal with integral types (and not with types like float and double)
 
 In order to understand how to tackle this problem we will first know how numbers are stored.
 
 About integers:
 ===============
 
 If the size of a data type is n bytes, it can store 2^n different values. This is called the data type's range.
 If size of an unsigned data type is n bytes, it ranges from 0 to 2^n-1
 If size of a signed data type is n bytes, it ranges from -2^n-1 to 2^n-1-1
 So, a short(usually 2 bytes) ranges from -32768 to 32767 and an unsigned short ranges from 0 to 65535
 
 Consider a short variable having a value of 250.
 It is stored int the computer like this (in binary format)
 00000000 11111010
 
 Complement of a number is a number with its bits toggled. It is denoted by ~
 For eg. ~250 is 11111111 00000101
 
 Negative numbers are stored using 2's complement system. According to this system, -n=~n+1
 -250 is stored as 11111111 00000110
 http://stackoverflow.com/questions/1049722/what-is-2s-complement
 
 10000000 00000000 (-32768) has no positive counterpart. Its negative is the number itself (try -n=~n+1)
 
 11100010 01110101 will be read as 57973 if data type is unsigned while it will be read as -7563 if data type is signed. If you add 65536 (which is the range) to -7563, you get 57973.
 
 Overflow:
 =========
 Consider a data type var_t of 1 byte (range is 256):
 signed var_t a,b;
 unsigned var_t c,d;
 
 If c is 200(11001000) and d is 100(01100100), c+d is 300(00000001 00101100), which is more than the max value 255(11111111). 00000001 00101100 is more than a byte, so the higher byte will be rejected and c+d will be read as 44. So, 200+100=44! This is absurd! (Note that 44=300-256). This is an example of an unsigned overflow, where the value couldn't be stored in the available no. of bytes. In such overflows, the result is moduloed by range (here, 256).
 
 If a is 100(01100100) and b is 50(00110010), a+b is 150(10010110), which is more than the max value 127. Instead, a+b will be read as -106 (note that -106=150-256). This is an example of a signed overflow, where result is moduloed by range(here, 256).
 
 Detecting overflow:
 ===================
 
 Division and modulo can never generate an overflow.
 
 Addition overflow:
 ==================
 Overflow can only occur when sign of numbers being added is the same (which will always be the case in unsigned numbers)
 signed overflow can be easily detected by seeing that its sign is opposite to that of the operands.
 
 Let us analyze overflow in unsigned integer addition.
 
 Consider 2 variables a and b of a data type with size n and range R.
 Let + be actual mathematical addition and a$b be the addition that the computer does.
 
 If a+b<=R-1, a$b=a+b
 As a and b are unsigned, a$b is more or equal to than both a and b.
 
 If a+b>=R a$b=a+b-R
 as R is more than both a and b, a-R and b-R are negative
 So, a+b-R<a and a+b-R<b
 Therefore, a$b is less than both a and b.
 
 This difference can be used to detect unsigned addition overflow. a-b can be treated as a+(-b) hence subtraction can be taken care of in the same way.
 
 Multiplication overflow:
 ========================
 There are two ways to detect an overflow:
 
 1.	if a*b>max, then a>max/b (max is R-1 if unsigned and R/2-1 if signed).
 2.	Let there be a data type of size n and range R called var_t and a data type of size 2n called var2_t.
 Let there be 2 variables of var_t called a and b. Range of var2_t will be R*R, which will always be more than the product of a and b. hence if var2_t(a)*var2_t(b)>R overflow has happened.
 
 Truncation:
 ===========
 This happens when a shorter is assigned from a longer variable. For eg, short a;long b=70000;a=b;Only the lower bits are copied and the value's meaning is translated.
 short a;int b=57973;a=b; will also show this behaviour become -7563.
 Similar behaviour will be shown if int is replaced by unsigned short.
 
 Type conversion:
 ================
 consider unsigned int a=4294967290;int b=-6; return (a==b); This returns 1.
 Whenever an operation is performed between an unsigned and a signed variable of the same type, operands are converted to unsigned.
 Whenever an operation is performed between a long type and a short type, operands are converted to the long type.
 The above code returned 1 as a and b were converted to unsigned int and then compared.
 If we used __int64 (a 64-bit type) instead of unsigned int and 18446744073709551610 instead of 4294967290, the result would have been the same.
 
 Type promotion:
 ===============
 Whenever an operation is performed on two variables of a type shorter than int, the type of both variables is converted to int. For eg. short a=32000,b=32000;cout<<a+b<<endl; would display 64000, which is more than the max value of short. The reason is that a and b were converted to int and a+b would return an int, which can have a value of 64000.
*/

#include <iostream>

int main(int argc, const char * argv[])
{
	
	/********* operands containing float & integer *********/

	std::cout << 1.4456f + 10 << std::endl; // here expression = float + int; so int will be converted to float. not vice versa. result will be in float.
	
	/* integer is converted to float
		integer / integer = integer. then integer is being converted to float.
	 */
	float f2 = static_cast<float>(13/2);
	std::cout << "f2=" << f2 << std::endl; // f2 = 6
	
	/* To avoid tuncation, we should perform division in float.
	 For that, one of the operand should be in float.
	 so float/int = float
	 */
	float f3 = static_cast<float>(13)/2;
	std::cout << "f3=" << f3 << std::endl; // f3 = 6.5xxx


	
	/**********  Overflow: ***********
		Overflow is a phenomenon where operations on 2 numbers exceeds the maximum 
		(or goes below the minimum) value the data type can have
	*/
	
	//Signed overflow
	signed short v1 = 30000;
	signed short v2 = 10000;
	signed short v3 = v1 + v2;
	std::cout << "v3 = " << v3 << std::endl;

	//Unsigned overflow
	unsigned short v4 = 60000;
	unsigned short v5 = 20000;
	unsigned short v6 = v4 + v5;
	std::cout << "v6 = " << v6 << std::endl;

	
	/*********** Truncation:**********
		This happens when a shorter is assigned from a longer variable.
	*/
	
	//signed
	short v7;
	int v8 = 57973;
	v7 = v8;
	std::cout << "v7 = " << v7 << std::endl;
	
	//unsigned
	unsigned short v9;
	unsigned int v10 = 80000;
	v9 = v10;
	std::cout << "v9 = " << v9 << std::endl;
	
	
	/*********** Type conversion ***********/
	
	/* Whenever an operation is performed between an unsigned and a signed variable
	   of the same type, operands are converted to unsigned.
	*/
	unsigned int v11 = 4294967290;
	int v12 = -6;
	std::cout << "v11 and v12 are " << (v11 != v12 ? "not ":"") << "equal" << std::endl;


	/*  Whenever an operation is performed between a long type and a short type,
		operands are converted to the long type.
	*/
	unsigned long long v13 = 18446744073709551610;
	int v14 = -6;
	std::cout << "v11 and v12 are " << (v13 != v14 ? "not ":"") << "equal" << std::endl;


	/*********** Type promotion:**********
		Whenever an operation is performed on two variables of a type shorter than int,
		the type of both variables is converted to int.
	*/
	
	int v15 = 1500000000;
	int v15_1 = 10;
	v15 = (v15 * v15_1) / v15_1; // int * 10 will be saved in a temp int. it overflows. so truncated. then divided by 10.
	std::cout << "v15 = " << v15 << std::endl;

	short v16 = 30000;
	short v17 = 10;
	v16 = (v16 * v17) / v17; // v16, v17 are converted to int first. then operation performed. (int * int)/int
							// 30000 * 10 can store in int without overflow. and then divided by int gives original value.
	std::cout << "v16 = " << v16 << std::endl;

	

	bool b = 42; // b is true
	int i = b;  // i = 1;
	i = 3.14; // i = 3
	double pi = i; // pi = 3.0
	unsigned char c = -1; // assuming 8-bit chars, c has value 255
	signed char v = 256; // v is 0
	
	
	
	/* When signed and unsigned operands are mixed */
	unsigned int va = 10;
	int vb = -42;
	std::cout << vb + vb << std::endl; // prints -84
	
	/* the size of unsigned operand type is >= to the signed operand type i.e 32 bit
	 therefore, the signed operand is converted to unsigned operand first */
	std::cout << va + vb << std::endl; // if 32-bit ints, prints 4294967264. not  -32
	
	
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

	return 0;
}
