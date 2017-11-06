//
//  main.cpp
//  InheritanceLevel
//
//  Created by abbas raza on 5/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Levels of inheritance.
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

 - How public and private inheritance work with levels. if Outer is private ( B below),
   inner becomes private if not (A below). If inner is private (A below) and outer is public
   (B below), inner remains private.
 ==========================================================================
 class A
 {
 }
 class B : public A
 {
 }
 class C : public B
 {
 }
 
 Inside B: You can access public/protected of A.
 Inside C: You can access pub/prot of B & A.
 Object of C: Can access pub of B and A.
 ==========================================================================
 class A
 {
 }
 class B : private A  // A is private of B. C won't be able to see it directly.
 {
 }
 class C : public B
 {
 }
 
 Inside B: You can access public/protected of A.
 Inside C: You can access pub/prot of B. Not of A.
 Object of C: Can access pub of B. not of A.
 ==========================================================================
 class A
 {
 }
 class B : public A
 {
 }
 class C : private B // B and A become private of C
 {
 }
 
 Inside B: You can access public/protected of A.
 Inside C: You can access pub/prot of B and A.
 Object of C: Cannot access pub of B, nor A.
 ==========================================================================
 class A
 {
 }
 class B : private A
 {
 }
 class C : private B
 {
 }
 
 Inside B: You can access public/protected of A.
 Inside C: You can access pub/prot of B but not A.
 Object of C: Cannot access pub of B, nor A.
 ==========================================================================
 
 - Here we can do 
 
 class chiefScientist : private Scientist, Employee
 {
 }
 
 But it would be wrong. ChiefScientist will be containing then 2 copies of Employee,
 1 from Scientist and other from Employee.

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

class chiefScientist : private Scientist
{
private:
	int scientists_under_supervision;
public:
	chiefScientist(std::string n = "", int i = 0, int p = 0, int supervising = 0) : Scientist(n, i, p), scientists_under_supervision(supervising)
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