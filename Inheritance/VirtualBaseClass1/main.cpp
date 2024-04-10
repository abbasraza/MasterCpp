//
//  main.cpp
//  VirtualBaseClass1
//
//  Created by abbas raza on 3/12/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Explore virtual base class.
 - Why we need virtual base class, to avoid 2 copies problem as below
 
  Diamond of death:
 
 	    ---
   --> | A | <--
  |     ---     |
  |             |
  |             |
 ---           ---
| B |         | C |
 ---           ---
  ^             ^
  |             |
  |             |
  |     ---     |
   --- | D | ---
	    ---

 -*****Previously we used to do:*****
 A
 {
 };
 
 
 B : public A // ok i will use my own copy of A
 {
 };
 
 C: public A // i will use my own copy of A
 {
 };
 
 D: public B, public C // 2 copies of A .
 {
 };
 
This causes D having 2 copies of A.
 
 D d;
 // Order of ctor calling
 1) ctor A ==> first copy
 2) ctor B
 3) ctor A ==> second copy
 4) ctor C
 5) ctor D

 - *****Solving it using virutal base class:*****
 class A
 {
 A(..) {};
 };
 
 class B : virtual public A
 {
 B(..) : A(..), data(..)
 };
 B says: whoever inherits me in multiple inheritance, i will share A with anyone who also wants to share A.
 
 
 class C : virtual public A
 {
 C(..) : A(..), data(..)
 };
 C says: whoever inherits me in multiple inheritance, i will share A with anyone who also wants to share A.
 
 
 Here D inherits B and C in multiple inheritance. And B, C are ready to share A.
 class D : public B, public C
 {
 D(..) : A(..), data(..), B(..), C(..)

 };

 - When we implement above example in code below, we learn:
	 - If a class inherits one or more classes that have virtual parents,
	   the most derived class is responsible for constructing the virtual base class.
	   D inherits B and C, both of which have a A virtual base class. D, the most derived class,
	   is responsible for creation of A.
	   D d;
	   // Order of ctor calling
	   1) ctor A
	   2) ctor B
	   3) ctor C
	   4) ctor D

	   Note that this is true even in a single inheritance case: if D was singly inherited from B,
	   and B was virtually inherited from A, D is still responsible for creating A.
 
	 - B and C constructors still have calls to the A constructor. When creating an instance of
	   D, these constructor calls are simply ignored because D is responsible for creating the A, not B or C.
	   However, if we were to create an instance of B or C, those constructor calls would be used, and normal
	   inheritance rules apply
 
	 - ???? TODO A virtual base class is always considered a direct base of its most derived
	   class (which is why the most derived class is responsible for its
	   construction). But classes inheriting the virtual base still need access to it.
	   So in order to facilitate this, the compiler creates a virtual table for each
	   class directly inheriting the virtual class (Printer and Scanner). These
	   virtual tables point to the functions in the most derived class. Because the
	   derived classes have a virtual table, that also means they are now larger by a
	   pointer (to the virtual table). ???? TODO
 
 
 - Also we learned in which order the ctors are called in inheritance:
 ---        ---
| A |      | B |
 ---        ---
  ^          ^
  |          |
  |          |
  |   ---    |
   --| C | --
	  ---
 
 case 1:
 class C : public B, public A
 {
 };
 C c; // 1) ctor of B called first, then A, then C
 
 case 2:
 class C : public A, public B
 {
 };
 C c; // 1) ctor of A called first, then B, then C

 so the ctor called in order we inherit.

 
 
 ################################################################

 Incorrect usage:
 A{};
 
B : virtual public A
{
};

C: public A
{
};

D: public B, public C // 2 copies of A
{
};

D d;  // ctor A --> ctor B  then ctor A ---> ctor  C  then ctor D
===============================
 Incorrect usage:
 A{};

B : virtual public A
{
};

C: public A
{
};

D: public A, public B // 2 copies of A ??
{
};

D d;  // ctor A --> ctor A --> ctor B --->  then ctor D
===============================

*/

#include <iostream>

class A
{
private:
	int var_a;
public:
	A(int v) : var_a(v)
	{
		std::cout << "Ctor of A" << std::endl;
	}
	void fA()
	{
		std::cout << "fA() var_a = " << var_a  << std::endl;
	}
};

class B : virtual public A
{
private:
	int var_b;
public:
	B(int v1, int v2) : A(v1), var_b(v2)
	{
		std::cout << "Ctor of B" << std::endl;
	}
	void fB()
	{
		//fA();
		//A::fA();
		std::cout << "fB() var_b = " << var_b << std::endl;
	}
};

class C : virtual public A
{
private:
	int var_c;
public:
	C(int v1, int v2) : A(v1), var_c(v2)
	{
		std::cout << "Ctor of C" << std::endl;
	}
	void fC()
	{
		//fA();
		//A::fA();
		std::cout << "fC() var_c = " << var_c << std::endl;
	}
};

class D : public B, public C
{
private:
	int var_d;
public:
	D(int v1, int v2, int v3, int v4) : var_d(v4), A(v1), B(v2,v1), C(v2,v3)
	{
		std::cout << "Ctor of D" << std::endl;
	}
	void fD()
	{
		fA();
		fB();
		fC();
		std::cout << "fD() var_d = " << var_d << std::endl;
	}
};

int main(int argc, const char * argv[])
{
	D d(1,2,3,4);
	d.fD();

	return 0;
}
