//
//  main.cpp
//  PointerArrayReference2
//
//  Created by abbas raza on 10/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>

/* Purpose of this program: TODO
 - Reference to int and pointer.
 - Pointer to reference conversion.
 
 int var = 10;
 const int var_const = 10;

 Reference to int:
 -----------------
 1) Non constant integer can be referred by:
 int & ref = var;
 const int & ref = var;
 
 2) constant integer can be referred by:
 int & ref = const_cast<int &>(var_const); //unsafe
 const int & ref = var_const;

 
 Reference to Pointer:
 ---------------------

 single pointer:
 ---------------
 p1) pointer to int
 p2) pointer to const int
 p3) const pointer to int
 p4) const pointer to const int

 pointer to reference conversion:
 --------------------------------
 r1) reference to (pointer to int) = p1
 int * &
 
 r2) reference to (pointer to const int) = p2
 const int * &
 
 r3) reference to (const pointer to int) = p1, p3
 int * const &
 
 r4) reference to (const pointer to const int) = p1, p2, p3, p4
 const int * const &

 
 r1 = p1 --> fine
 r1 = const_cast<int *>(p2)
 r1 = p3
 r1 = p4
 
 
 Reference to double pointer:
 ----------------------------
 7) reference to [pointer to (pointer to int)]
 TODO
 
*/

int main(int argc, const char * argv[])
{
	int var = 10;
	const int var_const = 10;

	int& ref1 = var;
	// we can also do:
	// const int & ref1 = var;
	std::cout << "ref1 = " << ref1 << std::endl;

	//int& ref2 = var_const; // can't do this
	int & ref2 = const_cast<int &>(var_const);
	//const int & ref2 = var_const; // works fine
	ref2 = 100;
	std::cout << "var_const = " << var_const << " ref2 = " <<  ref2 << std::endl;

	//pointer to integer
	int * p1 = &var;
	const int * p2 = &var;
	int * const p3 = &var;
	const int * const p4 = &var;

	/* r1) reference to (pointer to int) */
	//int * & r1 = p1;
	//   int * const &  r1 = const_cast<int * >(p2); // can't do this
	int * & r1 = const_cast<int*&>(p2);
	*r1 = 123;
	std::cout << "*r1 = " << *r1 << " *p2 = " << *p2 << std::endl;

#if 0
	int * r1t = const_cast<int *>(p3);
	int * & r1 = r1t;
	r1 = NULL; //works
	std::cout << "r1 = " << r1 << " p3 = " << p3 << std::endl;
#endif

#if 0
	// equal to:
	//int * const & r1 = const_cast<int *>(p3);
	
	// equal to:
	int * & r1 = const_cast<int * &>(p3);
	r1 = NULL; //works
	std::cout << "r1 = " << r1 << " p3 = " << p3 << std::endl;
#endif
	
	// int * & r1 = p4; // can't do this
	//*r1 = 1;
	
	/* r2) reference to (pointer to const int) */
	//const int * & r2 = p1; // can't do this
	const int * & r2 = p2;
	//const int * & r2 = p3; // can't do this
	//const int * & r2 = p4; // can't do this

	/* r3) reference to (const pointer to int) */
	//int * const & r3 = p1; 	// can do this
	//int * const & r3 = p2; 	// can't do this
	int * const & r3 = p3; 		// can do this
	//int * const & r3 = p4; 	// can't do this

	/* r4) reference to (const pointer to const int) */
	//const int * const & r4 = p1; // can do this
	//const int * const & r4 = p2; // can do this
	//const int * const & r4 = p3; // can do this
	const int * const & r4 = p4;


	return 0;
}
