//
//  main.cpp
//  ReinterpretCast
//
//  Created by abbas raza on 31/10/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - To find usage of reinterpret_cast.
 - Return a pointer to the same byte of memory, but just change the type of the pointer.
   (This is the same as what all pointer casts do in C, as explained above.)
 - For bit manipulation. where no calculation involved. just manipulation of address.
 - reinterpret_cast converts one pointer to another without changing the address, or converts
   between pointers and their numerical (integer) values.
 - reinterpret_cast says "Trust me, I know what I am doing. This looks totally wrong but it
   isn't. Just take these here bytes that you think are an X and treat them like a Y. It will be fine."
 - Templates:
   Problem with c-style casting: what if someone passes const int .
   template <class T>
   unsigned char* alias(T& x) {
		return (unsigned char*)(&x); ----> constness gone
   }
 
   c++: if someone passes const int
   template <class T>
   unsigned char* safe_alias(T& x) {
   return reinterpret_cast<unsigned char*>(&x); -----> error
   }
 - For opaque libraries. when static_cast doesn't work.
 
 - Compile time or runtime? TODO machine code / assembly difference?
*/

#include <iostream>

void print_binary(unsigned int * ptr)
{
	for(int i = 0; i < 32; ++i)
	{
		std::cout << ((*ptr & (1 << (31 - i))) >> (31 - i));
	}
	std::cout << std::endl;
}

bool is_little_endian()
{
	unsigned int x1 = 1;
	//0x7ffeefbff66c: 01 00 00 00
	unsigned char * p2 = reinterpret_cast<unsigned char *>(&x1);
	return (*p2 == 1);
}

int main()
{
	std::cout << "Is little endian?" << (is_little_endian() ? " YES" : " NO") << std::endl;
	float f1 = 1.0f;
	print_binary(reinterpret_cast<unsigned int *>(&f1));
	// 00111111100000000000000000000000
	return 1;
}