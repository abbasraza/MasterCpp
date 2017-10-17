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

 */

#include <iostream>

int main(int argc, const char * argv[])
{
	unsigned int a1 = 4294967295; // 0xff ff ff ff;
	float * a2 = reinterpret_cast<float *>(&a1); // Not a number. Exponent big?


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

	// We stored const float d4 =  101112131415.23456789101112131415161718192021222324252627f;

	if (d4 == 101112127488.0f)
	{
		std::cout << "Only 7 digits in non fractional part are correct" << std::endl;
	}

	return 0;
}
