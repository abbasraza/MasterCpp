//
//  main.cpp
//  String1
//
//  Created by abbas raza on 10/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Replace space with ,.
*/

#include <iostream>

int main(int argc, const char * argv[])
{
	std::string s1 = "Hello Kainaat Zehra";
	size_t index;
	while(1)
	{
		index = s1.find(' ');
		if (static_cast<signed>(index) > 0)
		{
			s1.replace(index, 1, 1, ',');
		}
		else
		{
			break;
		}
	}
	std::cout << s1 << std::endl;
	if (-1) // wrong way. Use -1 > 0
	{
		std::cout << "inside if for -1" << std::endl;
	}
}
