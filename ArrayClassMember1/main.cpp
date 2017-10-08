//
//  main.cpp
//  ArrayClassMember1
//
//  Created by abbas raza on 8/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of array of integers inside class.
*/

#include <iostream>

class foo
{
	int ar[10];
public:
	foo(): ar{1,2,3}
	{
	
	}

	foo(int v[])
	{
		for (int i = 0; i < 10; ++i)
		{
			ar[i] = v[i];
		}
	}
	
	void show_foo()
	{
		for(int i = 0; i < 10; ++i)
		{
			std::cout << ar[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main(int argc, const char * argv[])
{
	foo f1;
	f1.show_foo();

	int arr[10] = {1,3,4,5,6};
	
	foo f2(arr);
	f2.show_foo();

	return 0;
}