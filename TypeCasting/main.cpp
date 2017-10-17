//
//  main.cpp
//  TypeCasting
//
//  Created by abbas raza on 14/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>

void print_binary(int * ptr)
{
	for(int i = 0; i < 32; ++i)
	{
		std::cout << ((*ptr & (1 << (31 - i))) >> (31 - i));
	}
	std::cout << std::endl;
}

int main(int argc, const char * argv[])
{
	float var1 = .1f;
	//int var2 = static_cast<int>(var1);
	
	std::cout << "     00111101110011001100110011001101" << std::endl;
	
	/* Using static cast */
	void * ptr1 = static_cast<void *>(&var1);
	int * ptr2 = static_cast<int *>(ptr1);
	std::cout << "ptr2 ";	print_binary(ptr2);

	/* C-Style cast */
	int * ptr3 = (int *)&var1;
	std::cout << "ptr3 ";	print_binary(ptr3);
	
	/* Using reinterpret_cast */
	int * ptr4 = reinterpret_cast<int *>(&var1);
	std::cout << "ptr4 ";	print_binary(ptr4);

	void * ptr5 = reinterpret_cast<void *>(&var1);
	int * ptr6 = reinterpret_cast<int *>(ptr5);
	std::cout << "ptr6 ";	print_binary(ptr6);

	int var2 = reinterpret_cast<int>(var1);
	//std::cout << std::bitset<32>(*ptr4) << std::endl;
	//std::cout << *ptr4 << std::endl;

	return 0;
}
