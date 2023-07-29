//
//  main.cpp
//  ArrayOfStruct
//
//  Created by abbas raza on 5/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of array of structures.
*/

#include <iostream>

struct temperature
{
	int max;
	int min;
};

void get_cities_temperatures(struct temperature ct[])
{
	ct[0].max = 40;
	ct[0].min = 20;
	ct[1] = {35, 18};
	ct[2] = {30, 15};
	ct[3] = {20, 10};
}

void print_cities_temperatures(struct temperature ct[])
{
	for(int i = 0; i < 4; ++i)
	{
		std::cout << "City # " << i << " max:" << ct[i].max << " min:" << ct[i].min << std::endl;
	}
}

int main(int argc, const char * argv[]) {

	struct temperature cities_temperatures[4] = {0};
	print_cities_temperatures(cities_temperatures);

	get_cities_temperatures(cities_temperatures);
	
	print_cities_temperatures(cities_temperatures);
	
	return 0;
}
