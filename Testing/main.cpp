//
//  main.cpp
//  Testing
//
//  Created by abbas raza on 16/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//
#include <iostream>


bool is_little_endian()
{
	unsigned short x = 0x0001;
	//auto p = reinterpret_cast<unsigned char*>(&x);
	
	void * ptr = &x;
	auto p = static_cast<unsigned char *>(ptr);
	return *p != 0;
}

int main()
{
	//unsigned int i1 = 0xffffffff;
	unsigned short s1 = 0x1204;
	std::cout << "Little_Endian: " << is_little_endian() << std::endl;
	return 1;

}