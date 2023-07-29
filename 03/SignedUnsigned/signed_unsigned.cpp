//
//  main.cpp
//  SignedUnsigned
//
//  Created by abbas raza on 6/05/2017.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>

void print_unsigned_number_in_binary(unsigned char num, const char * given_num)
{
	int n = num;
	std::cout << given_num << " stored in unsigned char becomes " << n << " = ";
	//printf("printf %s stored in unsigned char becomes %d = ", given_num, num);
	for (int i = (sizeof(unsigned char) * 8) - 1; i >= 0; --i)
	{
		std::cout << ((num & (1 << i)) >> i);
		if (i % 4 == 0)
			std::cout << " ";
	}
	
	std::cout << std::endl;
}

void print_signed_number_in_binary(signed char num, const char * given_num)
{
	int n = num;
	/* 
		movsbl -0x14(%rbp),%eax 
	 
		Here we are trying to store a signed char in integer type.
		integer is 32 bit (on this platform)
		signed char is 8 bit.
	 
		so if num = 1111 1111 = 0xff; (check sign bit = 1)
		and we move it to n. will n be = 0000 0000 0000 0000 0000 0000 1111 1111 ?
		i.e will n = 0x000000ff ?
		No. whenever we assign a signed char to int, compiler will place sign extended move
		instruction in assembly (move 8 bit to 32 bit with not losing sign). So n will be = 0xffffffff;
	*/
	
	signed char b = n;
	
	std::cout << given_num << " stored in signed char becomes " << n << " = ";
	//printf("printf %s stored in signed char becomes %d = ", given_num, num);
	
	for (int i = (sizeof(signed char) * 8) - 1; i >= 0; --i)
	{
		std::cout << ((num & (1 << i)) >> i);
		if (i % 4 == 0)
			std::cout << " ";
	}
	
	std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
	
	unsigned char unum1 = -1;
	/* 
		movb   $0xff,-0xa(%rbp)

		-1 is -ve number, so compiler will generate assembly like this.
		i.e compiler will take 2's compliment of 1 and place it in assembly.
		2's compliment of 1:
		1 = 0000 0001
		Step 1) invert all bits
				1111 1110
		Step 2) add 1
				(1111 1110 + 1) = 1111 1111 = 0xff
	 */

	unsigned char unum2 = 1;
	/* movb   $0x1,-0x9(%rbp) */
	 
	unsigned char unum3 = 255;
	/* movb   $0xff,-0x8(%rbp) */
	
	unsigned char unum4 = 256;
	/* 
		movb   $0x0,-0x7(%rbp)
		unsigned char has only 8 bit space.
		while 256 = 1 0000 0000
		so only first 8 bits will be stored in variable (on stack).
	 */
	
	signed char num1 = -1;
	/*
		movb   $0xff,-0x6(%rbp) 

		-1 is -ve number, so compiler will generate assembly like this.
		i.e compiler will take 2's compliment of 1 and place it in assembly.
		2's compliment of 1:
		1 = 0000 0001
		Step 1) invert all bits
			1111 1110
		Step 2) add 1
			(1111 1110 + 1) = 1111 1111 = 0xff
	*/

	signed char num2 = 1;
	/* movb   $0x1,-0x5(%rbp) */

	signed char num3 = 127;
	/* movb   $0x7f,-0x4(%rbp) */
	
	signed char num4 = 128;
	/* 
		movb   $0x80,-0x3(%rbp) 
	 
		signed char range is from -127 to 127.
		because we use bit 7 for sign.
		here 128 = 1000 0000. 
		Compiler will place it as it is in assembly code.
	*/
	
	signed char num5 = 255;
	/* 
		movb   $0xff,-0x2(%rbp)
		
		Again signed char range is from -127 to 127.
		because we use bit 7 for sign.
		here 255 = 1111 1111.
		Compiler will place it as it is in assembly code.
	 */
	
	signed char num6 = 256;
	/* 
		movb   $0x0,-0x1(%rbp) 
	 
		signed char has only 8 bit space (1 bit for sign).
		while 256 = 1 0000 0000
		so only first 8 bits will be stored in variable (on stack).
	*/
	
	
	print_unsigned_number_in_binary(unum1, "-1");
	print_unsigned_number_in_binary(unum2, "1");
	print_unsigned_number_in_binary(unum3, "255");
	print_unsigned_number_in_binary(unum4, "256");
	
	print_signed_number_in_binary(num1, "-1");
	print_signed_number_in_binary(num2, "1");
	print_signed_number_in_binary(num3, "127");
	print_signed_number_in_binary(num4, "128");
	print_signed_number_in_binary(num5, "255");
	print_signed_number_in_binary(num6, "256");
	
	return 0;
}