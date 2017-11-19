//
//  main.cpp
//  CStringCopy
//
//  Created by abbas raza on 7/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of stpcpy(char * dst, const char * src);
 - strcpy() functions copy the string src to dst (including the terminating `\0' character.)
    Normal copying doesn't.
*/

#include <iostream>

int main(int argc, const char * argv[])
{
	char str1[100];
	char str2[100] = {[0 ... 99] = '?'};
	char str3[] = "ABCD EFG HIJK LMN OP";

	strcpy(str1, str3);

	std::cout << "str1 = " << str1 << std::endl;

	for (int i = 0; i < strlen(str3); ++i)
	{
		str2[i] = str3[i];
	}

	//	str2[strlen(str3)] = '\0'; //If not placed, whole string will be printed.
	std::cout << "str2 = " << str2 << std::endl;

	return 0;
}
