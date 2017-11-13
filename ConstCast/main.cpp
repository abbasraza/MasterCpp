//
//  main.cpp
//  ConstCast
//
//  Created by abbas raza on 11/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

//- NOTE: CODE IS MESS HERE. READ RULES AND CONCLUSIONS INSTEAD.

/* Purpose of this program:
 - Only changes cv-qualification; all other casts cannot cast away constness. Can't change type. can't convert float to int.
 - Removing constness from pointers:
 ~~~~~~~~~~~~~~~~~~
 - Single pointer:
 ~~~~~~~~~~~~~~~~~
 #################Rule for implicit conversion:#################
	 pointer to int = &var_const; // won't work. need const cast. actual int shouldn't be constant.
	 this can be put as --> pointer to int = pointer to const int; // won't work. need const cast. actual int shouldn't be constant.
#################Conclusion of explicit conversion using const_cast:#################
	 we need explicit conversion (const_cast) to remove integer constness from a (single pointer to const int).
	 But it will work SAFELY only if actual object is not constant as below
 
	 int v = 10
	 const int * ptr1 = &v1
	 int * ptr2 = const_cast<int *>(ptr1)

 ~~~~~~~~~~~~~~~~~~
 - Double pointer:
 ~~~~~~~~~~~~~~~~~~
#################Rule for implicit conversion:#################
	 a) lvalue inner pointer has same type as rvalue inner pointer
	 OR
	 {
	 b) pointer to constant pointer to constant int = any
	 AND
	 c) pointer to constant pointer to int = pointer to pointer to int
	 }
	 d) (outer most constant pointer) can be converted to (outer most non-constant pointer).
	 e) (outer most non constant pointer) can be converted to (outer most constant pointer).
#################Conclusion of explicit conversion using const_cast:#################
	 1) we can remove constness of int. (SAFELY only if actual int is non constant)
	 2) we can add constness to int. // not safe?? not needed?? TODO
	 3) we can remove constness of inner pointer.
	 4) we can add constness to inner pointer. // not safe?? not needed??

 
 v1) int var = 10;
 v2) const int var_const = 10;
 
 Pointer:
 ========
 1) pointer to int 									--> int * ptr1 = &var;
 2) pointer to const int							--> const int * ptr2 = &var_const; or const int * ptr2 = &var;
 3) const pointer to int							--> int * const ptr3 = &var;
 4) const pointer to const int						--> const int * const ptr4 = &var_const; or const int * const ptr4 = &var;

 
 
 Pointer to int:
 ==============
 Rule1: pointer to int = &var_const; // won't work. need const cast. actual int shouldn't be constant.
 +++++
 
 1 = &v2; // can't do this without explicit conversion
 1 = const_cast<int*>(&v2); //undefined behavior
 
 3 = &v2; // can't do this without explicit conversion
 3 = const_cast<int * const>(&v2); //undefined behavior
 
 1 = &v1; //good
 3 = &v1; //good
 
 2 = &v1; //good
 2 = &v2; //good
 
 4 = &v1; //good
 4 = &v2; //good
 
 Pointer conversion:
 ===================
 Rule = Rule1: pointer to int = pointer to const int; // won't work. need const cast. actual int shouldn't be constant.
 +++++++++++++
 
 1 = 1/2/3/4;
 ###########
========> 1 = 2; // can't do this without explicit conversion.
 
		 Case 1: Actual object is not constant:
		 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		 if 2 is equal to ---> const int * ptr = &var;
		then
		 1 = const_cast<int *>(ptr); // will work fine.
 
		 Case 2: Actual object is constant:
		 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		 if 2 is equal to ---> const int * ptr = &var_const;
		 then
		 1 = const_cast<int *>(ptr); // will have undefined behaviour.

========> Similarly 1 = 4; // can't do this without explicit conversion.
 
		 Case 1: Actual object is not constant:
		 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		 if 4 is equal to ----> const int * const ptr = &var;
		 then
		 1 = const_cast<int *>(ptr); //will work fine.
 
		 Case 2: Actual object is constant:
		 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		 if 4 is ----> const int * const ptr = &var_const;
		 then
		 1 = const_cast<int *>(ptr); // will have undefined behaviour.

 2 = 1/2/3/4:
 ###########
		 2 = 1/2/3/4 // good. no explicit conversion needed.
 
 3 = 1/2/3/4:
 ###########
		 3 = 2 // can't do without explicit conversion. Same problem as 1 = 2
		 3 = 4 // can't do without explicit conversion. Same problem as 1 = 4

 4 = 1/2/3/4:
 ###########
		 4 = 1/2/3/4 // good. no explicit conversion needed.

 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 CONCLUSION 1: a) we don't need explicit conversion (const_cast) to remove constness of a single pointer.
			 b) we need explicit conversion (const_cast) to remove integer constness from a (single pointer to const int).
			 But it will work fine only if actual object is not constant as below
 
			 int v = 10
			 const int * ptr1 = &v1
			 int * ptr2 = const_cast<int *>(ptr1)
 
			 c) we can cast a constant integer to (int *). But result will be undefined.
 
			 So only use case is b) above.
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
 Double pointer:
 ===============
 5) pointer to (pointer to int)						--> int ** ptr5 = &ptr1;
 6) pointer to (pointer to const int)				--> const int ** ptr6 = &ptr2;
 7) pointer to (const pointer to int)				--> int * const * ptr7 = &ptr3;
 8) pointer to (const pointer to const int)			--> const int * const * ptr8 = &ptr4;
 9) const pointer to (pointer to int)				--> int ** const ptr9 = &ptr1;
 10) const pointer to (pointer to const int)		--> const int ** const ptr10 = &ptr2;
 11) const pointer to (const pointer to int)		--> int * const * const ptr11 = &ptr3;
 12) const pointer to (const pointer to const int)	--> const int * const * const ptr12 = &ptr4;
 
 Conversion between double pointers listed above: (From 5 to 12)
 ---------------------------------------------------------------
 Rule 2: (for implicit conversion)
 ++++++
 
 a) lvalue inner pointer has same type as rvalue inner pointer
 OR
 {
 b) pointer to constant pointer to constant int = any
 AND
 c) pointer to constant pointer to int = pointer to pointer to int
 }
 d) (outer most constant pointer) can be converted to (outer most non-constant pointer).
 e) (outer most non constant pointer) can be converted to (outer most constant pointer).

 Pointer heading from above:
 ==========================
 1) pointer to int 									--> int * ptr1 = &var;
 2) pointer to const int							--> const int * ptr2 = &var_const; or const int * ptr2 = &var;
 3) const pointer to int							--> int * const ptr3 = &var;
 4) const pointer to const int						--> const int * const ptr4 = &var_const; or const int * const ptr4 = &var;

 ############################################################
 pointer to pointer = &pointer;
 ############################################################
 Follow Rule 2
 
 5 and 9 case:
 ------------------
 5 = &1 --> true;
 5 = all others with explicit const_cast. we can remove pointer constness, int constness, both. If int constness is changed, it will be safe if actual int is non constant.
 9 = &1 --> true;
 9 = all other similar to 5 = all other.

 6 and 10 case:
 ------------------
 6 = &2	--> true;
 6 = &4 with explicit const_cast. we can remove pointer constness.
 10 = &2 --> true;
 10's rest is same like 6.

 7 and 11 case:
 ------------------
 7 = &1, &3 --> true;
 7 = &2, &4 with explicit const_cast. we can remove int constness. only if it is safe. as mentioned above
 11 = &1, &3 --> true;
 11's rest is same as 7.

 8 and 12 case:
 --------------
 8 = &1, &2, &3, &4 --> true;
 12 = &1, &2, &3, &4 --> true;
 
 
############################################################
pointer to pointer = pointer to pointer;
############################################################
Follow rule 2
 
 5 = 7 --> cant work. need casting --> int ** ptrt = const_cast<int**>(ptr7);
 5 = 5,9 --> it means 5 = 9 works. 5 = 5 works
 9 = 5,9 --> can
 ^ ^ ^ same as (same as 5 and 9 case above)

 
 6 = 6,10 --> it means 6 = 10 works.
 10 = 6,10 --> can
 ^ ^ ^ same as (same as 6 and 10 case above)

 7 = 5,7,9,11 --> it means 7 = 7 works. and 7 = 9 works and 7 = 11 works.
 11 = 5,7,9,11 --> can
 ^ ^ ^ same as (same as 7 and 11 case above)

 8 = ALL 5,6,7,8,9,10,11,12 --> all conversions work
 12 = ALL 5,6,7,8,9,10,11,12 --> all conversions work

 CONCLUSION 2:
 +++++++++++
  1) we can remove constness of int. (safe only if actual int is non constant)
  2) we can add constness to int.
  3) we can remove constness of inner pointer.
  4) we can add constness to inner pointer.

 Reference: TODO
 ==========
 Actual variable is not constant:
 ---------------------------------
 1) const int& ref = nonconstant_var;
 int& reft = const_cast<int&>ref; --> should work

 Actual variable is constant: (Actual variable's constness shouldn't be removed)
 -----------------------------
 1) const int& ref = constant_var;
 int& reft = const_cast<int&>ref; --> should work. But will lead to undefined behavior.


   const_cast can be safely used to remove constness from a reference or a pointer used to access
   a non-const object. But if your actual object is declared const, that constness can never be removed.
   Modifying a const object through a non-const access path results in undefined behavior.
 - Usage of const_cast
 - How const_cast can cast const char * pointer returned by c_str() to non constant pointer.
 - We then use this pointer to modify original string.
 
 - Compile time or runtime? TODO machine code / assembly difference?
*/

#include <iostream>

int main(int argc, const char * argv[])
{
	std::string s1 = "Hello Abbas Raza";
	std::cout << "len of s1 " << s1.length() << std::endl;
	std::cout << "capacity of s1 " << s1.capacity() << std::endl;

	const char * str = s1.c_str();
	std::strcpy(const_cast<char *>(str), "Ihavemodifiedthestring");
	std::cout << "len of s1 " << s1.length() << std::endl;
	std::cout << "capacity of s1 " << s1.capacity() << std::endl;
	
	std::cout << "s1 = " << s1 << std::endl;
	
	const std::string s2 = "Hello Abbas Raza";
	const char * str2 = s1.c_str();
	std::strcpy(const_cast<char *>(str2), "Ihavemodifiedthestring");
	std::cout << "s2 = " << s2 << std::endl;

	
	/* Where do we need const cast */
	/* Where can we use const cast safely */
	
	int v1 = 10;
	const int v2 = 10;

	// POinters:
	//int * ptr1
	//const int * ptr2
	//int * const ptr3
	//const int * const ptr4
	
	/******** Pointer to int ********/
	//int * ptr1 = &v2; // can't do this without explicit conversion
	int * ptr1 = const_cast<int*>(&v2); //undefined behavior
	
	//int * const ptr3 = &v2; // can't do this without explicit conversion
	int * const ptr3 = const_cast<int * const>(&v2); //undefined behavior
	
	//int * ptrt = &v1; //good
	//int * const ptrt = &v1; //good
	
	//const int * ptrt = &v1; //good
	//const int * ptrt = &v2; //good
	
	//const int * const ptrt = &v1; //good
	//const int * const ptrt = &v2; //good

	
	/*Pointer conversion:
	  ===================
		1 = 1/2/3/4;
	    ###########
		========> 1 = 2; // can't do this without explicit conversion.
	
		Case 1: Actual object is not constant:
		~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		if 2 is equal to ---> const int * ptr = &var;
		then
		1 = const_cast<int *>(ptr); // will work fine.
	 */
	const int * ptr4 = &v1; // --> 2
	int * ptr5 = const_cast<int *>(ptr4); // will work fine.
	
	/*
		Case 2: Actual object is constant:
		~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		if 2 is equal to ---> const int * ptr = &var_const;
		then
		1 = const_cast<int *>(ptr); // will have undefined behaviour.
	 */
	const int * ptr6 = &v2;
	int * ptr7 = const_cast<int *>(ptr6); // undefined behavior
	

	/*
	 ========> Similarly 1 = 4; // can't do this without explicit conversion.
	 
	 Case 1: Actual object is not constant:
	 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 
	 if 4 is equal to ----> const int * const ptr = &var;
	 then
	 1 = const_cast<int *>(ptr); //will work fine.
   */
	const int * const ptr8 = &v1;
	int * ptr9 = const_cast<int *>(ptr8); // will work fine
	
	/*
	 Case 2: Actual object is constant:
	 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	 if 4 is ----> const int * const ptr = &var_const;
	 then
	 1 = const_cast<int *>(ptr); // will have undefined behaviour.
 */
	const int * const ptr10 = &v2;
	int * ptr11 = const_cast<int *>(ptr10); // undefine behavior
	
	/*  2 = 1/2/3/4:
	 ###########
	 2 = 1/2/3/4 // good. no explicit conversion needed.
	 */
	int * ptr12 = &v1;
	int * const ptr13 = &v1;
	const int * const ptr14 = &v1;
	//const int * ptr15 = ptr12; // work fine
	//const int * ptr15 = ptr13; // work fine
	//const int * ptr15 = ptr14; // work fine
	

	/* Similarly:
	 3 = 1/2/3/4:
	 ###########
	 3 = 2 // can't do without explicit conversion. Same problem as 1 = 2
	 3 = 4 // can't do without explicit conversion. Same problem as 1 = 4
	 
	 4 = 1/2/3/4:
	 ###########
	 4 = 1/2/3/4 // good. no explicit conversion needed.
	 */

#if 0
	
	/* Removing constness of a const pointer */
	// We have a constant pointer
	int * const ptr4 = &v2;

	// At somepoint in program, we want to NULL this pointer.
	// but we can't do this way:
	// ptr4 = NULL;
	
	// but we can use double pointer for this purpose.
	// pointer to pointer to int = remove constness of (const pointer to int)
	int ** ptr5 = const_cast<int**>(&ptr4);
	*ptr5 = NULL;
	std::cout << "ptr4 = " << ptr4 << std::endl;
	
	/* Removing constness from a reference when reference to const int = int */
	int t2 = 10;
	const int& t2_ref = t2;
	//t2_ref = 100; //can't do this
	int& t3_ref = const_cast<int&>(t2_ref);
	t3_ref = 100; // can do this
	std::cout << "t2 = " << t2 << " t3_ref = " << t3_ref << std::endl;

	/* Undefined behaviou: Removing constness from a reference when reference to const int = const int */

	const int t4 = 10;
	const int& t4_ref = t4;
	int& t5_ref = const_cast<int&>(t4_ref);
	t5_ref = 100;
	std::cout << "t4 = " << t4 << " t5_ref = " << t5_ref << std::endl;

#endif
	
    return 0;
}
