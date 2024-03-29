//
//  main.cpp
//  FloatVsDouble
//
//  Created by abbas raza on 16/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/*
 TODO: more time needed. comparing floats proper method. more practice and use cases, understanding.

 Purpose of this program:
 - Comparison between float and double.
 - Use double is you want more accurate values. i.e more precision (more error free digits)
 
 Given a quadratic equation:
 x^2 − 4.0000000 x + 3.9999999 = 0
 the exact roots to 10 significant digits are, 
 r1 = 2.000316228 and r2 = 1.999683772.

 If we use float, roots are:
 r1 = 2
 r2 = 2

 if we use double, roots are:
 r1 = 2.000316227765758
 r2 = 1.999683772234242

*/

#include <iostream>
#include <math.h>

void print_binary(void * v)
{
	unsigned int * ptr = static_cast<unsigned int *>(v);
	
	for(int i = 0; i < 32; ++i)
	{
		std::cout << ((*ptr & (1 << (31 - i))) >> (31 - i));
	}
	std::cout << std::endl;
}


void dbl_solve(double a, double b, double c)
{
	double d = b * b - 4.0 * a * c;
	double sd = sqrt(d);
	double r1 = (-b + sd) / (2.0 * a);
	double r2 = (-b - sd) / (2.0 * a);
	std::cout << r1 << "	";
	std::cout << r2 << std::endl;
}

void flt_solve(float a, float b, float c)
{
	float d = b * b - 4.0f * a * c;
	float sd = sqrtf(d);
	float r1 = (-b + sd) / (2.0f * a);
	float r2 = (-b - sd) / (2.0f * a);
	std::cout << "r1 "; print_binary(&r1);
	std::cout << "r2 "; print_binary(&r2);

	std::cout << r1 << "	";
	std::cout << r2 << std::endl;
}

int main(void)
{
	std::cout.precision(16);

	float fa = 1.0f;
	float fb = -4.0000000f;
	float fc = 3.99999999f;  // Float precision is 7 decimals digits

	double da = 1.0;
	double db = -4.0000000;
	double dc = 3.9999999;

	flt_solve(fa, fb, fc);
	dbl_solve(da, db, dc);

	return 0;
}