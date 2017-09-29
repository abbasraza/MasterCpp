//
//  main.cpp
//  StaticData1
//
//  Created by abbas raza on 28/09/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of static data.
 - If you want to share something between all objects, make it static.
 */

#include <iostream>

class Cigarette
{
private:
	static int smoked_count; // All objects will share this variable
	
	// can this static be constant? yes. But no changing inside the class.
	// static const int smoked_count; // All objects will share this variable
public:
	Cigarette()
	{
		++smoked_count;
	}
	void show_smoked()
	{
		std::cout << "You have smoked " << smoked_count << " cigarette" << std::endl;
	}
};

int Cigarette::smoked_count = 11; // exists when there is no object. lifetime = entire program
//const int Cigarette::smoked_count = 11; // exists when there is no object. lifetime = entire program

int main(int argc, const char * argv[])
{
	Cigarette s1;
	Cigarette s2, s3;
	Cigarette s4;
	
	s1.show_smoked();

	return 0;
}
