//
//  main.cpp
//  Reference1
//
//  Created by abbas raza on 29/09/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of reference (Alias). Just a different name for a variable.
 - Reference in assignment.
 - Pass by reference.
 - Return by reference. 
	- Reference to local variable.
	- Reference to global variable.
	- Reference on left side of = . Means original variable will be changed.
	- Reference on right side of =. Means original variable will remain unchanged.
  
 Assign reference:
 =================
    int& v = some variable name (lets say i); // reference defined.
    v = some variable name (lets say j); // value of j stored in v and so i.
 
 Return reference:
 ==================
 int global_variable;
 int& foo()
 {
	return global_variable; // return some gloabal variable name.
 }
 
 foo() = 10; // means reference to global_variable = 10; i.e global_variable = 10.
 OR 
 int& t = foo(); // means int& t = global_variable;
 t = 10; // means global_variable = 10;
 
 int t1 = foo(); // means t1 = global_variable. i.e t1 = 10;
 t1 = 20; // means global_variable = unchanged. t1 = 20.
*/


#include <iostream>

int x = 0;

void perform_square(int& v)
{
	v = v * v;
}

int& foo1() // returning reference to local variable is wrong.
{
	int temp = 15;
	return temp; // unknown value. reference to local variable returned. incorrect.
}

int& foo2() // return alias to an int.
{
	/*
	int& t =  x; // return alias to globar int variable x.
	return t;
	 */
	 //or you can simply do:
	 return x;
	
}

int main(int argc, const char * argv[]) {

	int i = 2;
	int& j = i; // j is another name of i
	int& k = j; // k is another name of j. i.e k is another name of i.
	int m = 3;
	//int& m; // reference always needs initialization. not just declaration.
	//int& m = 2; // reference is always towards some address not value.

	std::cout << "Address of i " << &i << std::endl;
	std::cout << "Address of j " << &j << std::endl;
	std::cout << "Address of k " << &k << std::endl;

	std::cout << "Value of i " << i << std::endl;
	std::cout << "Value of j " << j << std::endl;
	std::cout << "Value of k " << k << std::endl;

	int& t = foo1(); // t is another name of local stack variable temp. Wrong!!
	std::cout << "Value of t " << t << std::endl;

	perform_square(j);
	std::cout << "Value of t " << t << std::endl;

	k = m; // this is values assignment as usual. value in t assigned to k which is alias of i,j.
	std::cout << "Value of i " << i << std::endl;
	std::cout << "Value of j " << j << std::endl;
	std::cout << "Value of k " << k << std::endl;

	foo2() = 10;
	/* Above statement is same as
	   int& t1 = square3();
	   t1 = 10;
	 */

	std::cout << "Value of x " << x << std::endl;

	int t1 = foo2();
	t1 = 20;
	std::cout << "Value of t1 " << t1 << std::endl;

	std::cout << "Value of x " << x << std::endl;

    return 0;
}
