//
//  main.cpp
//  NewAndDelete1
//
//  Created by abbas raza on 14/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of dynamic memory allocation with new and delete.
 - new vs malloc . we don't need casting with new.
 - new will throw bad_alloc exception if memory allocation failed.
   if exception is not handled, program will crash. To avoid exception,
   place (std::nothrow) between new and type. Now new will return null pointer
   if memory allocation fails.
 - delete frees memory. but doesn't null pointer. so null pointer after delete.
*/

 
#include <iostream>

int main(int argc, const char * argv[])
{
	/* Dynamic allocation of integer */
	int * ptr1 = new int; // no need to cast as compared to malloc
	std::cout << "*ptr1 = " << *ptr1 << std::endl;

	int * ptr2 = new int();
	std::cout << "*ptr2 = " << *ptr2 << std::endl;

	int * ptr3 = new int(10);
	std::cout << "*ptr3 = " << *ptr3 << std::endl;

	int * ptr4 = new int{20};
	std::cout << "*ptr4 = " << *ptr4 << std::endl;

	/* new will throw bad_alloc exception if memory allocation failed.
	   if exception is not handled, program will crash. To avoid exception,
	   place (std::nothrow) between new and type. Now new will return null pointer
	   if memory allocation fails.
    */
	int * ptr5 = new (std::nothrow) int;
	if (ptr5 == NULL)
	{
		std::cout << "Failed to allocate memory" << std::endl;
	}

	/* delete free memory. doesn't null pointer */
	delete ptr1;
	delete ptr2;
	delete ptr3;
	delete ptr4;
	delete ptr5;

	std::cout << "ptr1 = " << ptr1 << std::endl;
	std::cout << "ptr2 = " << ptr2 << std::endl;
	std::cout << "ptr3 = " << ptr3 << std::endl;
	std::cout << "ptr4 = " << ptr4 << std::endl;
	std::cout << "ptr5 = " << ptr5 << std::endl;

	ptr1 = ptr2 = ptr3 = ptr4 = ptr5 = NULL;
	
	std::cout << "ptr1 = " << ptr1 << std::endl;
	std::cout << "ptr2 = " << ptr2 << std::endl;
	std::cout << "ptr3 = " << ptr3 << std::endl;
	std::cout << "ptr4 = " << ptr4 << std::endl;
	std::cout << "ptr5 = " << ptr5 << std::endl;

	return 0;
}
