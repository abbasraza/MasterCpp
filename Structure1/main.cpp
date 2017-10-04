//
//  main.cpp
//  Structure1
//
//  Created by abbas raza on 4/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Returning structure by value.
 - Passing structure by value.
 - Passing structure by reference.
 - Returning structure by referece. --> I don't understand when we need this return by reference.

*/

#include <iostream>

struct temperature
{
	int max;
	int min;
};

struct temperature get_temp()
{
	struct temperature t = {29, 15};
	return t;
}

void get_temp2(struct temperature& t)
{
	std::cout << "Address of t in func " << &t << std::endl;
	t.max = 41;
	t.min = 25;
}

int main(int argc, const char * argv[])
{
	struct temperature t1 = get_temp();
	std::cout << "max: " << t1.max << " min: " << t1.min << std::endl;
	
	std::cout << "Address of t1  " << &t1 << std::endl;

	get_temp2(t1);

	std::cout << "max: " << t1.max << " min: " << t1.min << std::endl;
	
    return 0;
}