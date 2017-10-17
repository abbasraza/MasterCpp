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
*/

#include <iostream>

void print_float_to_bin(float& v)
{
	void * ptr = &v;
	int * ptr2 = ptr;

	for(int i = 0; i < 32; ++i)
	{
		std::cout << ((*ptr2 & (1 << (31 - i))) >> (31 - i));
	}
	std::cout << std::endl;
}

int main(int argc, const char * argv[])
{
	std::cout.precision(30);
	float v = 0.1f;
	
	print_float_to_bin(v);
	//float a = 1.999;
	//int b = -10;

//	std::cout << .1f << std::endl;
//	float a = 0.1f + 0.3f;
//	float b = 0.1f + 0.4f;
//
//	/* Here one operand is float and other is int. So other will be converted to float.
//	   Result will be in float.
//	*/
//	//std::cout << a + b << std::endl;
//	std::cout << a << std::endl;
//	std::cout << b << std::endl;
//	
//	while (0)
//	{
//		float v1 = 0.15f + 0.15f;
//		float v2 = 0.1f + 0.2f;
//		if (v1 != v2)
//		{
//			std::cout << "NOT EQUALLLLLLLLLLL" << std::endl;
//			break;
//		}
//	}
	return 0;
}
