//
//  main.cpp
//  InheritanceLevel2
//
//  Created by abbas raza on 6/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - A derived class can call only its direct base's ctor in its ctor initializer list.
   i.e ChiefScientist can't call Employee ctor in its initializer list.
 
    ----------
   | Employee |
    ----------
	     ^
	     |
	     |
    -----------
   | Scientist |
    -----------
	     ^
	     |
	     |
  ----------------
 | ChiefScientist |
  ----------------

*/

#include <iostream>

class Employee
{
private:
	std::string name;
	int id;
public:
	Employee(std::string n = "", int i = 0) : name(n), id(i)
	{
	}
	void show_employee()
	{
		std::cout << "Name: " << name << '\n' << "ID: " << id << std::endl;
	}
};

class Scientist : public Employee
{
private:
	int publications;
public:
	Scientist(int p = 0) : publications(p)
	{
	}

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

class chiefScientist : public Scientist
{
private:
	int scientists_under_supervision;
public:
	chiefScientist(std::string n = "", int i = 0, int p = 0, int supervising = 0) : Employee(n, i), Scientist(p), scientists_under_supervision(supervising)
	{
	}
	void show_chiefscientist()
	{
		show_scientist();
		std::cout << "Supervising: " << scientists_under_supervision << std::endl;
	}
};

int main(int argc, const char * argv[])
{
	Scientist s("Abbas", 17);
	s.show_scientist();
	
	chiefScientist cs("chief sb", 10, 59, 5);
	cs.show_chiefscientist();
	
	return 0;
}