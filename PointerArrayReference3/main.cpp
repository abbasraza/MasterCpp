//
//  main.cpp
//  PointerArrayReference3
//
//  Created by abbas raza on 12/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Use of 1d/2d array of int
 - Use of array of int pointers
 - Use of 1d/2d array of characters
 - TODO: reference to array
 - VLA (variable lenght array) on stack. Determining the lenght of array at run time.
 - VLA on heap using (malloc?)
*/

#include <iostream>

void func1(int array[], int len)
{
	//int size = sizeof(array) / sizeof(int); //wrong. sizeof(array) here will be size of int *.
	for (int i = 0; i < len; ++i)
	{
		std::cout << array[i] << std::endl;
	}
}

void func2(int array[], int len)
{
	//int size = sizeof(array) / sizeof(int); //wrong. sizeof(array) here will be size of int *.
	for (int i = 0; i < len; ++i)
	{
		std::cout << *array++ << std::endl;
	}
}

void func3(int * array, int len)
{
	//int size = sizeof(array) / sizeof(int); //wrong. sizeof(array) here will be size of int *.
	for (int i = 0; i < len; ++i)
	{
		std::cout << *array++ << std::endl;
	}
}

void func4(int * array, int len)
{
	//int size = sizeof(array) / sizeof(int); //wrong. sizeof(array) here will be size of int *.
	for (int i = 0; i < len; ++i)
	{
		std::cout << array[i] << std::endl;
	}
}

void func9(int * array[])
{
	for (int i = 0; i < 2; ++i)
	{
		std::cout << *array[i] << std::endl;
	}
}

void func5(int ** array)
{
	for (int i = 0; i < 2; ++i)
	{
		std::cout << **(array + i) << std::endl;
	}
}

void func6(int ** array)
{
	for (int i = 0; i < 2; ++i)
	{
		std::cout << array[i][0] << std::endl;
	}
}

void func7(int array[][1])
{
	for (int i = 0; i < 2; ++i)
	{
		std::cout << array[i][0] << std::endl;
	}
}

void func8(int * array)
{
	for (int i = 0; i < 2; ++i)
	{
		std::cout << *(array+i) << std::endl;
	}
}

void func10(int array[][4], int r, int c)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			std::cout << "array[" << i << "][" << j << "] = " << array[i][j] << std::endl;
		}
	}
}

void func11(int ** array, int r, int c)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			std::cout << "array[" << i << "][" << j << "] = " << array[i * c + j] << std::endl;
		}
	}
}

void func12(char array[])
{
	std::cout << "array = " << array << std::endl;
}

void func13(char * array)
{
	std::cout << "array = " << array << std::endl;
}

void func14(char array[][4], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}
}

void func15(char * array[], int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}
}

void func16(char ** array, int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}
}

void func17(char ** array, int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		std::cout << "array[" << i << "] = " << *(array + i) << std::endl;
	}
}

void fill_array(int * array, int len)
{
	for (int i = 0; i < len; ++i)
	{
		array[i] = i;
	}
}

int main(int argc, const char * argv[])
{
	/*
	 ############################################################
	 ######## 1d Array of int and passing to functions ##########
	 ############################################################
    */
	//array of int
	int array1[] = {1,2,3};
	std::cout << "size of array1 = " << sizeof(array1) << std::endl;
	int len1 = sizeof(array1) / sizeof(int);
	//passing array of int to func. All funcs same
	func1(array1, len1);
	func2(array1, len1);
	func3(array1, len1);
	func4(array1, len1);
	for (int i = 0; i < len1; ++i)
	{
		//std::cout << *array1++ << std::endl; // can't do this. actual name of array.
	}

	// reference to array
	//int * & ref1 = &array1[0];

	// array of const int
	const int array2[] = {1,2,3};
	//*(const_cast<int *>(&array2[0])) = 11; // bad undefined behavior UB
	//(const_cast<int &>(array2[0])) = 11; // UB
	//int & ref1 = const_cast<int&>(array2[0]);
	//ref1 = 11;

	int var1 = 10;
	int var2 = 20;

	/*
	 ##################################################################
	 ######## Array of int pointers and passing to functions ##########
	 ##################################################################
	 */

	int * array3[] = {&var1, &var2};

	//std::cout << *array3[0] << std::endl;
	func5(array3);
	func6(array3);
	//func7(array3); // wrong
	//func8(array3); // wrong
	func9(array3);

	/*
	 #####################################################################
	 ######## 2d Array of int and passing to functions ###################
	 #####################################################################
	 */

	//int array4[][] = {{1,2,3,4}, {5,6,7,8}}; // wrong
	int array4[][4] = {{1,2,3,4}, {5,6,7,8}};
	func10(array4, 2, 4);
	//func11(array4, 2, 4);

	/*
	 #####################################################################
	 ######## 1d Array of char and passing to functions ##################
	 #####################################################################
	 */

	char array5[] = "Hello";
	const char * array6 = "Hello";
	func12(array5);
	func13(array5);
	func12(const_cast<char *>(array6));
	func13(const_cast<char *>(array6));

	/*
	 #####################################################################
	 ######## 2d Array of char and passing to functions ##################
	 #####################################################################
    */
	//char array7[][4] = {"1234", "5689", "abcd"}; we can only have 3 coloums. last will be null character
	/* Fixed length strings */
	char array7[][4] = {"123", "568", "acd"}; // in memory: 123\0568\0acd\0
	/* Variable lenght strings */
	char * array8[] = {"123456", "789", "abcdedgh"}; // in memory: addr_of_string1 addr_of_string2 addr_of_string3

	func14(array7, 3);
	//func14(array8, 3); wrong
	func15(array8, 3);
	func16(array8, 3);
	func17(array8, 3);

	
	/*
	 #####################################################################
	 ############ 			VLA (Variable Length Array)		 #############
	 #####################################################################
	 */

	int i;
	std::cout << "Enter lenght of array:";
	std::cin >> i;
	int array9[i];

	fill_array(array9, i);
	func1(array9, i);
	return 0;
}
