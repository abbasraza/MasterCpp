//
//  main.cpp
//  PointerToPointer
//
//  Created by abbas raza on 1/05/2017.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
	
	int num1 = 10;
	int num2 = 20;
	
	int * array_of_int_ptr[2];
	
	array_of_int_ptr[0] = &num1;
	array_of_int_ptr[1] = &num2;
	
	cout << "printing using array of int ptr" << endl;
	for (int i = 0; i < 2; ++i)
	{
		cout << "element " << i << " = " << *array_of_int_ptr[i] << endl;
	}
		
	int ** double_ptr = static_cast<int **>(array_of_int_ptr);
	
	cout << "printing using double pointer" << endl;
	for (int i = 0; i < 2; ++i)
	{
		cout << "element " << i << " = " <<  **(double_ptr + i) << endl;
	}

	**(double_ptr) = 5;
	**(double_ptr + 1) = 15;
	
	cout << "printing using double pointer after modification" << endl;
	for (int i = 0; i < 2; ++i)
	{
		cout << "element " << i << " = " <<  **(double_ptr + i) << endl;
	}

    return 0;
}
