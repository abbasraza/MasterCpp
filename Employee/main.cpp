//
//  main.cpp
//  Employee
//
//  Created by abbas raza on 4/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Abstract class. Employee here is abstract because we never will create an object for this.
 - Usage of inheritance.
 - Scope resolution is required when we need to instruct compiler how to serve our call. i.e
   when there is a chance that compiler will get confused if we don't tell it.
*/

#include <iostream>

class Employee
{
private:
	std::string name;
	int id;
protected:
	Employee(std::string n = "", int i = 0) : name(n), id(i)
	{
	
	}
	void show_employee()
	{
		std::cout << "Name: " << name << '\n' << "ID: " << id << std::endl;
	}
};

class Scientist : private Employee
{
private:
	int publications;
public:
	Scientist(std::string n = "", int i = 0, int p = 0) : Employee(n, i), publications(p)
	{
		
	}
	void show_scientist()
	{
		//Employee::show_employee(); // don't need scope resolution here.
		show_employee();
		std::cout << "Publications: " << publications << std::endl;
 	}
};

class Labor : public Employee
{
public:
	Labor(std::string n = "", int i = 0) : Employee(n, i)
	{
		
	}
	void show_labor()
	{
		//Employee::show_employee();
		show_employee(); // don't need scope resolution here.
	}
};

int main(int argc, const char * argv[])
{
	Scientist e1("Abbas", 17);
	Labor e2("Shahg", 100);

	e1.show_scientist();
	e2.show_labor();

	return 0;
}
