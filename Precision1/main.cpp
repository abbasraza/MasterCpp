//
//  main.cpp
//  Precision1
//
//  Created by abbas raza on 16/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - What is precision? Precision is number of decimal digits which can be used safely 
   (which contain no error i.e which are not approximation)
 - Float type is single precision. precision is 7 or 8 decimal digits. So 7 decimal digits are safe, rest are approximation.
 - Double type is double precision. precision is 15 or 16 decimal digits.
 - what about range then? float range is 3e38?
 - This program shows that if we assign a real number having more than 7 decimal digits to a float type, 
   only first 7 decimal digits
TODO: more time needed. comparing floats proper method. more practice and use cases, understanding.
 */

#include <iostream>
#include <iomanip> // setprecision
#include <sstream> // stringstream
#include <float.h>
#include <math.h> 

//void is_equal(float f1, float f2)
//{
//	std::stringstream stream1, stream2;
//	stream1 << std::fixed << std::setprecision(10) << f1;
//	stream2 << std::fixed << std::setprecision(10) << f2;
//
//	std::string s1 = stream1.str();
//	std::string s2 = stream2.str();
//
//	if (f1 == f2)
//	{
//		std::cout << s1 << " is equal to " << s2 << std::endl;
//	}
//	else
//	{
//		std::cout << s1 << " is not equal to " << s2 << std::endl;
//	}
//}

void print_binary(void * v)
{
	unsigned int * ptr = static_cast<unsigned int *>(v);
	
	for(int i = 0; i < 32; ++i)
	{
		std::cout << ((*ptr & (1 << (31 - i))) >> (31 - i));
	}
	std::cout << std::endl;
}

int nearlyEqual (float a, float b, float eps)
{
	float absA = fabs(a);
	float absB = fabs(b);
	float diff = fabs(a - b);
	if (a == b)
	{
		// shortcut, handles infinities
		return true;
	}
	else if (a == 0 || b == 0 || diff < FLT_MIN)
	{
		// a or b is zero or both are extremely close
		// to it; relative error is less meaningful here
		return (diff < (eps * FLT_MIN));
	} else {
		// use relative error
		return (diff / (absA + absB) < eps);
	}
}

int main(int argc, const char * argv[])
{
	std::cout.precision(16);

	/* Int to float conversion....Undefined */
	unsigned int a1 = 4294967295; // 0xff ff ff ff;
	float * a2 = reinterpret_cast<float *>(&a1); // Not a number. Exponent big?

	std::cout << "a1 is " << a1 << std::endl;
	std::cout << "a2 is " << *a2 << std::endl;

	/* First 9 significant digits are equal */
	//is_equal(0.123456789101112f, 0.123456789213141f);

	/* First 8 significant digits are equal */

	float f3 = 0.8910111213141516f;
	float f4 = 0.8910111277777777f;

	if (f3 == f4)
	{
		std::cout << "f3 == f4" << std::endl;
	}

	/* First 8 significant digits are equal */

	float f5 = 1.8910111213141516f;
	float f6 = 1.8910111777777777f;

	if (f5 == f6)
	{
		std::cout << "f5 == f6" << std::endl;
	}

	/* First 8 significant digits (0's here are not significant) are not equal */

	float f7 = 0.000000000012345678f;
	float f8 = 0.000000000012345678f;

	if (f7 == f8)
	{
		std::cout << "f7 == f8" << std::endl;
	}

	float f9  = 0.12340000000f;
	float f10 = 0.1234f; // 0.123f fails

	if (f9 == f10)
	{
		std::cout << "f9 == f10" << std::endl;
	}

	float f11 = 0.12340000000f;
	float f12 = 0.01234f;

	if (f11 == f12)
	{
		std::cout << "f11 == f12" << std::endl;
	}

	/* These are actually equal */
	float f13 = 123456789000.0f;
	float f14 = 123456789999.0f;

	if (f13 == f14)
	{
		std::cout << "f13 == f14" << std::endl;
	}
	std::cout << "f13 binary "; print_binary(&f13);
	std::cout << "f14 binary "; print_binary(&f14);

	float f15 = 0.1f + 0.2f;
	float f16 = 0.15f + 0.15f;

	std::cout << "f15 binary "; print_binary(&f15);
	std::cout << "f16 binary "; print_binary(&f16);

	if (f15 == f16) // This can be false? use proper method for comparing floating point numbers.
	{
		std::cout << "f15 == f16" << std::endl;
	}

#if 0
	
	/* non fractional part 0, fractional large */
	const double d1 = 0.23456789101112131415161718192021222324252627;
	const float d2 = 0.23456789101112131415161718192021222324252627f;

	/* non fractional part large, fractional 0 */
	const double d3 = 10111213141516171819202122.0;
	const float d4 =  10111213141516171819202122.0f;

	/* both parts large */
	const double d5 = 10111213141516171819202122.23456789101112131415161718192021222324252627;
	const float d6 =  10111213141516171819202122.23456789101112131415161718192021222324252627f;

	const float d7 =  3e38;

	const float f1 = 123123123123123123123123123123123123112.11111111111111111111111111111111111111111111114012984643248171213211111111111111111111111111111111111111111111111111111111111111123132123132131313131313131313131113131321312131231231231231231231231231231231231231231313123123123131231231232342342353453453453453453453453453453453453453453535353535353535353535353535353535353535353575876864512341415236647456352416542315654326543276542312f;
	
	const float f2 = 1231231231231231231231231231231231231122.0f;
	
	std::cout << "The  default precision is " << std::cout.precision() << "\n\n";
	
	std::cout << "With default precision a1 is " << a1 << std::endl;
	std::cout << "With default precision a2 is " << *a2 << std::endl;

	std::cout << "With default precision d1 is " << d1 << std::endl;
	std::cout << "With default precision d2 is " << d2 << std::endl;
	
	std::cout << "With default precision d3 is " << d3 << std::endl;
	std::cout << "With default precision d4 is " << d4 << std::endl;
	
	std::cout << "With default precision d5 is " << d5 << std::endl;
	std::cout << "With default precision d6 is " << d6 << std::endl;
	
	std::cout << "With default precision d7 is " << d7 << std::endl;

	std::cout.precision(100);

	std::cout << "With high precision d1 is " << d1 << std::endl;
	std::cout << "With high precision d2 is " << d2 << std::endl;
	
	std::cout << "With high precision d3 is " << d3 << std::endl;
	std::cout << "With high precision d4 is " << d4 << std::endl;
	
	std::cout << "With high precision d5 is " << d5 << std::endl;
	std::cout << "With high precision d6 is " << d6 << std::endl;
	
	std::cout << "With high precision d7 is " << d7 << std::endl;
	
	std::cout << "f1 " << f1 << std::endl;
	std::cout << "f2 " << f2 << std::endl;
#endif
	return 0;
}
