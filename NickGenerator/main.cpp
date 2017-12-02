//
//  main.cpp
//  NickGenerator
//
//  Created by abbas raza on 1/05/2017.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int get_random(size_t range)
{
	return (rand() % range);
}

int main(int argc, const char * argv[]) {
	
	srand(static_cast<unsigned int>(time(NULL)));

	//char * name = "abdeirsyz";
	const char * name = static_cast<const char *>("abbasrazazaidi");
	char * array[50000];
	size_t range = strlen(name);
	for (int i = 0; i < 50000; ++i)
	{
		//cout << name[get_random(range)] << name[get_random(range)] << name[get_random(range)] << name[get_random(range)] << name[get_random(range)] << endl;
		*(array + i) = new char[6];
		*(*(array+i) + 0) = name[get_random(range)];
		*(*(array+i) + 1) = name[get_random(range)];
		*(*(array+i) + 2) = name[get_random(range)];
		*(*(array+i) + 3) = name[get_random(range)];
		*(*(array+i) + 4) = name[get_random(range)];
		*(*(array+i) + 5) = '\0';

		cout << static_cast<const char *>(*(array+i)) << endl;
	}
    return 0;
}
