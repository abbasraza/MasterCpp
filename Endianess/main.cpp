//
//  main.cpp
//  Endianess
//
//  Created by abbas raza on 18/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
   - Write program to find endianess of machine.
*/

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
	return 1;
}