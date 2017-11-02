//
//  main.cpp
//  ConversionDiffObjs
//
//  Created by abbas raza on 1/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Conversion between objects of different classes.
 - There are 2 ways. only one can be used. 1) to use operator convertor in src. 2) to use 1 argument ctor in dest.

 - A objectOfA;
   B objectOfB;

 - objectOfA = objectOfB;
   2 ways:
   1) objectOfB is src. operator convertor in src.
   OR
   2) objectOfA is dest. single argument ctor in dest.
 
 - objectOfB = objectOfA;
   2 ways:
   1) objectOfA is src. operator convertor in src.
   OR
   2) objectOfB is dest. single argument ctor in dest.

 - Which method should be used? Which ever you can. if you are using a 3rd party library
   and don't have source code of it, and src is part of that library. Then implement conversion in dest.
   and vice versa.
 - Use of forward declaration.
 - Use of header files.
*/

#include <iostream>

#define USE_METHOD_2

#include "Time24.hpp"
#include "Time12.hpp"

#ifdef USE_METHOD_2
Time12::Time12(Time24 t)
{
	h = (t.get_hours() > 12 ? t.get_hours() - 12 : t.get_hours());
	m = t.get_minutes();
	s = t.get_seconds();
	before_noon =  t.get_hours() > 11 ? 0 : 1;
}
#else
Time24::operator Time12()
{
	return Time12((h > 12 ? h - 12 : h), m, s, h > 11 ? 0 : 1);
}
#endif

int main(int argc, const char * argv[])
{
	Time12 t1(5,4,40, 0);
	t1.show_time();

	Time24 t2(17,4,40);
	t2.show_time();

	std::cout << "24 hours to 12 hours conversion" << std::endl;
	Time12 t3 = t2;
	t3.show_time();


    return 0;
}