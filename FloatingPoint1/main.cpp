//
//  main.cpp
//  FloatingPoint1
//
//  Created by abbas raza on 14/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//


/*
 TODO: more time needed. comparing floats proper method. more practice and use cases, understanding.

 Purpose of this program: 
 
 - What are Floating point numbers
 - Needed for storing real numbers. Actually approximation of real numbers. Because we can't exactly store a number like PI.
 - What is fixed point number
 - Floating point numbers are just Scientific notation in binary
 - How they are stored in memory
 - exponent/mantisa/sign,
 - Why they are stored in scientific notation,
 - How they are converted back to decimal, range????
 - IEEE 754.
 - Not equal in == statements but look equal to user. i.e .1f which is recurring in binary and needs truncation.
 - What is precision? Single vs Double precision?
 - Comparing float and double.
 - Which one to use, float or double?
 - Default floating point constants are double. suffix f=float/single precision and l=long double.
   An unsuffixed floating constant has type double. If suffix is the letter f or F, the floating
   constant has type float. If suffix is the letter l or L, the floating constant has type long double.
 - Difference between double and long double??
 - 18.46e1 means 18.46 x 10^1
 - hexadecimal float constant?
 - converting double to float and vice versa?
 - float, double, and long double.
 
	 How large/small real numbers are stored/used?
	 What is floating point representation scientific notation? exponent/mantissa/sign?
	 Binary fraction?
	 normalize number?
	 How to convert real number to binary floating point representation?
	 Rounding errors, why adding 1 to last bit?
	 what is precision? what is precision of float and double? 7 decimal digits? 16 decimal digits?
	 which one to use float OR double?? Depends float=less space, less precision. check floatvsdouble program.
	 Max value float can hold? minimum value float can hold?
	 Max value double can hold? minumum value double can hold?
	 How float stored? from representation in code to binary/registers/assembly?
	 How large can be the non-fractional part and fractional part?
	 how changing precision cout works?
	 float and double comparison?
	 float and double conversion?
	 double vs long double?
	 By default double (un suffixed)
	 Arithmetic conversion . expression involving float and int etc. int will be converted to float.
	 why no limit on how many digits we can append after . decimal point??
	 IEEE 754
	 comparison of floating point numbers?
	 double decreases speed?
	 
 
 Docs important: what every programmer should know about floating point numbers.
 youtube videos
 https://www.youtube.com/watch?v=PZRI1IfStY0&t=252s
 https://www.youtube.com/watch?v=k12BJGSc2Nc&t=769s
 
 Calculator:
 https://www.h-schmidt.net/FloatConverter/IEEE754.html
 
 
 http://sandbox.mc.edu/~bennet/cs110/flt/dtof.html
 
 
 
 Floating Point numbers:
 
 Why needed:
 To store real numbers like 0.1231241 , 0.5, 1.124124142 in machine.
 
 We cant just say, 16 bit for storing fractional part and rest for storing non fractional part.
 Because we can have different scenarios.
 
 1.124124141241
 30000000000.123
 in which we need space for storing many different fractional parts.
 
 
 
 How decimal are stored in binary:
 in scientific notation
 
 lets assume 32 bit machine.
 
 <sign> = 1 bit
 <Exponent> = 8bit
 <Mantissa> = 23 bit
 
 lsb = least significant bit
 msb = most significant bit
 
 msb						lsb
 <sign> < Exponent> <Mantisa>
 
 
 
 Read in docs : Decimal to Floating-Point Conversions Missipi college.
 and floating point to decimal.
 Also read why 0.1 doesn't exit in floating point doc
 
 
 
 
 
 float(decimal) to Binary?? Decimal to floating point conversion??
 .1
 
 0
 0.1 * 2 = .2  = 0
 .2 * 2 = .4 = 0;
 .4 * 2 = .8 = 0;
 .8 * 2 = 1.6 = 1;
 .6 * 2 = 1.2 = 1;
 .2 * 2 = .4 = 0;
 .4 * 2 = .8 = 0;
 .8 * 2 = 1.6 = 1;
 .6 * 2 = 1.2 = 1;
 .2 * 2 = .4 = 0;
 .4 * 2 = .8 = 0;
 .8 * 2 = 1.6 = 1;
 .6 * 2 = 1.2 = 1;
 .2 * 2 = .4 = 0;
 .4 * 2 = .8 = 0;
 .8 * 2 = 1.6 = 1;
 .6 * 2 = 1.2 = 1;
 .2 * 2 = .4 = 0;
 .4 * 2 = .8 = 0;
 .8 * 2 = 1.6 = 1;
 .6 * 2 = 1.2 = 1;
 .2 * 2 = .4 = 0;
 .4 * 2 = .8 = 0;
 .8 * 2 = 1.6 = 1;
 .6 * 2 = 1.2 = 1;
 .2 * 2 = .4 = 0;
 .4 * 2 = .8 = 0;
 ........
 
 
 0.00011001100110011001100110011001100110011.......
 
 Normalize --> move . to after 1
 1.1001100110011001100110011001100110011 * 2 ^ -4
 
 -4 + 127 = 123 = 0111 1011 --> exp 8 bits
 ignore first 1 (because same in every conversion) and .
 10011001100110011001100 --> mantisa 23 bits
 0x4CCCCC
 
 
 1036831949 = 0 01111011 10011001100110011001101  --> last bit = 1 means some rounding mechanism for truncation.
 
 Binary to Float (decimal)?? floating point to decimal conversion??
 
 exp = 01111011 = 123(decimal)
 --> 123 - 127 = -4
 
 Denormalize mantisa -- > 1.10011001100110011001101
 
 1.10011001100110011001101  * 2 ^ -4
 
 1234 56789
 = .0001 1001	1001	1001	1001	1001	101
 
 1/16 +  1/32 + 1/256 + 1/512 + 1/4096 + 1/8192 +
 .0625 + .0312 + .00390625 + 001953125 + .000244140625 + .0001220703125 + .00001525878906 + .00000762939453 +

 
*/


#include <iostream>

void print_binary(void * v)
{
	unsigned int * ptr = static_cast<unsigned int *>(v);
	
	for(int i = 0; i < 32; ++i)
	{
		std::cout << ((*ptr & (1 << (31 - i))) >> (31 - i));
	}
	std::cout << std::endl;
}

int main(int argc, const char * argv[])
{
	float v1 = 0.1f;
	float v2 = 1.2f;
	int v3 = 200;
	float v4 = -0.1f;
	float v5 = 1.2;		// is this equivalent to static_cast<float>(1.2)? I think so
	double v6 = 1.2;

	std::cout << "v1 = ";	print_binary(&v1);
	std::cout << "v2 = ";	print_binary(&v2);
	std::cout << "v3 = ";	print_binary(&v3);
	std::cout << "v4 = ";	print_binary(&v4);
	std::cout << "v5 = ";	print_binary(&v5);
	std::cout << "v6 = ";	print_binary(&v6);

	if (v5 == 1.2)
	{
		std::cout << "Condition 1 True" << std::endl;
	}
	
	if (v5 == static_cast<float>(1.2))
	{
		std::cout << "Condition 2 True" << std::endl;
	}

	//float v2 = 0.12312312313131313112312312313123123131313112212312313131f;

	return 0;
}