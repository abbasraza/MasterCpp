//
//  main.cpp
//  Array4
//
//  Created by abbas raza on 6/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Initializing 1D, 2D and array of structures to 0 or some other value all together.
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
	
	ct[2].max = 30;
	ct[2].min = 15;
	
	ct[3].max = 20;
	ct[3].min = 10;
}

void print_cities_temperatures(struct temperature ct[])
{
	for(int i = 0; i < 4; ++i)
	{
		std::cout << "City # " << i << " max:" << ct[i].max << " min:" << ct[i].min << std::endl;
	}
}

void print_1d_array(int ar[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		std::cout << ar[i] << " ";
	}
	std::cout << std::endl;
}

void print_2d_array(int ar[][4], int r, int c)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			std::cout << ar[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, const char * argv[])
{
	/* Zero sized array:
	 What the hell is this initialization way???
	 This is called a way to get flexible sized array
	 This is used at end of structure i.e 0 sized array.
	 int ar[0];
	 or 
	 int ar[] = {};
	 
	 struct example
	 {
		int v;
		int ar[0];
	 }
	 
	 then use malloc to have flexible array size.
	 */
	//int a = 77;
	int array1[] = {}; /// ??? what is this? unbounded array!!!
	//array1[0] = 1;
	//array1[1] = 2; // This will corrupt a.
	//std::cout << a << std::endl;
	std::cout << "Size of array1 = " << sizeof(array1) << std::endl;

	int array2[0];
	std::cout << "Size of array2 = " << sizeof(array2) << std::endl;

	/* Initializing a 1D array to 0 */
	int array3[4] = {};
	std::cout << "Array3 --> ";
	print_1d_array(array3, 4);
	
	int array4[4] = {0};
	std::cout << "Array4 --> ";
	print_1d_array(array4, 4);
	
	/* Initializing a 1D array to some value */
	int array5[4] = {[0 ... 3] = 10};
	std::cout << "Array5 --> ";
	print_1d_array(array5, 4);

	int array6[4] = {[0 ... 1] = 10, [2 ... 3] = 5};
	std::cout << "Array6 --> ";
	print_1d_array(array6, 4);

	/* 2D array */
	
	/* Zero sized array */
	int array7[][4] = {};
	std::cout << "Size of array7 = " << sizeof(array7) << std::endl;

	int array8[0][0];
	std::cout << "Size of array8 = " << sizeof(array8) << std::endl;

	/* initialize to 0 */
	int array9[4][4] = {};
	std::cout << "Array9:" << std::endl;
	print_2d_array(array9, 4, 4);
	
	int array10[4][4] = {0};
	std::cout << "Array10:" << std::endl;
	print_2d_array(array10, 4, 4);

	/* Initialize to some values */
	int array11[4][4] = {1}; // only first element 1, rest 0
	std::cout << "Array11:" << std::endl;
	print_2d_array(array11, 4, 4);

	int array12[4][4] = {1,2,3,4}; // only first row defined
	std::cout << "Array12:" << std::endl;
	print_2d_array(array12, 4, 4);

	int array13[4][4] = {[0 ... 3] = 1}; // set row # 0 to 3 to 1. i.e first element of each row set to 1.
	std::cout << "Array13:" << std::endl;
	print_2d_array(array13, 4, 4);

	int array14[4][4] = {[0 ... 3] = {1, 2, 3, 4}}; // set row # 0 to 3 to {1,2,3,4} each.
	std::cout << "Array14:" << std::endl;
	print_2d_array(array14, 4, 4);

	int array15[4][4] = {{[0 ... 3] = 1}}; // set row # 0 index 0 to 3 to 1.
	std::cout << "Array15:" << std::endl;
	print_2d_array(array15, 4, 4);

	int array16[4][4] = {{[0] = 1}, {[1] = 1}, {[2] = 1}, {[3] = 1}}; // set diagonal = 1.
	std::cout << "Array16:" << std::endl;
	print_2d_array(array16, 4, 4);


	/* Zero size array of structures */
	
	struct temperature cities_temperatures1[] = {};
	std::cout << "size of cities_temperatures1 array " << sizeof(cities_temperatures1) << std::endl;
	
	struct temperature cities_temperatures2[0];
	std::cout << "size of cities_temperatures2 array " << sizeof(cities_temperatures2) << std::endl;
	
	/* Initializing array of structs to 0 */
	struct temperature cities_temperatures3[4] = {};
	std::cout << "cities_temperatures3 Array" << std::endl;
	print_cities_temperatures(cities_temperatures3);
	
	/* Initializing 1d array of struct to some value */
	struct temperature cities_temperatures4[4] = {1,2,3,4,5,6,7,8}; // all the structure elements initialized
	std::cout << "cities_temperatures4 Array" << std::endl;
	print_cities_temperatures(cities_temperatures4);
	
	struct temperature cities_temperatures5[4] = {{11,12}, {13,14}, {15,16}, {17,18}}; // all the structure elements initialized
	std::cout << "cities_temperatures5 Array" << std::endl;
	print_cities_temperatures(cities_temperatures5);

	struct temperature cities_temperatures6[4] = {[0 ... 3] = {100, 80}}; // all the structure elements initialized
	std::cout << "cities_temperatures6 Array" << std::endl;
	print_cities_temperatures(cities_temperatures6);
	
	struct temperature cities_temperatures7[4] = {[0 ... 2] = {100, 80}, [3] = {90, 10}}; // all the structure elements initialized
	std::cout << "cities_temperatures7 Array" << std::endl;
	print_cities_temperatures(cities_temperatures7);

	return 0;
}
