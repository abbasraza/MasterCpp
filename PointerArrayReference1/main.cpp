//
//  main.cpp
//  PointerArrayReference1
//
//  Created by abbas raza on 8/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>

/* Purpose of this program:
 - To understand single and double pointers.
 - To understand conversion between single pointers.
 - To understand conversion between double pointers.
 - How to remember trick:
	 Read from right to left.
	 const int * const * const ptr;
								 <-------- This way : ptr is a constant pointer to constant pointer to constant int
 
 - ####### SEE FINAL CONCLUSIONS AND RULES AT THE END OF THIS COMMENT #######
 
 int var = 10;
 const int var_const = 10;

 1) pointer to int 									--> int * ptr1 = &var;
 2) pointer to const int							--> const int * ptr2 = &var_const; or const int * ptr2 = &var;
 3) const pointer to int							--> int * const ptr3 = &var;
 4) const pointer to const int						--> const int * const ptr4 = &var_const; or const int * const ptr4 = &var;
 5) pointer to (pointer to int)						--> int ** ptr5 = &ptr1;
 6) pointer to (pointer to const int)				--> const int ** ptr6 = &ptr2;
 7) pointer to (const pointer to int)				--> int * const * ptr7 = &ptr3;
 8) pointer to (const pointer to const int)			--> const int * const * ptr8 = &ptr4;
 9) const pointer to (pointer to int)				--> int ** const ptr9 = &ptr1;
 10) const pointer to (pointer to const int)		--> const int ** const ptr10 = &ptr2;
 11) const pointer to (const pointer to int)		--> int * const * const ptr11 = &ptr3;
 12) const pointer to (const pointer to const int)	--> const int * const * const ptr12 = &ptr4;
 
 13) Conversion between single pointers listed above: (From 1 to 4)
 --------------------------------------------------------------
 Rule:
 ====
 a)
 pointer to int = pointer to const int; // won't work. need const cast. actual int shouldn't be constant.
 pointer to x = const pointer x; //works
 const pointer to x = pointer to x; //works
 
 b) rest works fine.
 
  1 = 1,3		--> can do this
  1 = 2,4		--> can't do this. need const cast
  2 = 1,2,3,4	--> can do this
  3 = 1,3 		--> can
  3 = 2,4 		--> cant. need const cast
  4 = 1,2,3,4 	--> can

 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 SEE 'ConstCast' FOR EXPLICIT CONVERSIONS
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
 Conversion between double pointers listed above: (From 5 to 12)
 ---------------------------------------------------------------
 Rule:
 ====
 a) lvalue inner pointer has same type as rvalue inner pointer
 OR
 {
 b) pointer to constant pointer to constant int = any
 AND
 c) pointer to constant pointer to int = pointer to pointer to int
 }
 d) (outer most constant pointer) can be converted to (outer most non-constant pointer).
 e) (outer most non constant pointer) can be converted to (outer most constant pointer).

 
 5 = &1 --> true;
 6 = &2	--> true;
 7 = &1, &3 --> true;
 8 = &1, &2, &3, &4 --> true;
 9 = &1 --> true;
 10 = &2 --> true;
 11 = &1, &3 --> true;
 12 = &1, &2, &3, &4 --> true;

 
 5 = 7 --> cant work. need casting --> int ** ptrt = const_cast<int**>(ptr7);
 5 = 5,9 --> it means 5 = 9 works.
 6 = 6,10 --> it means 6 = 10 works.
 7 = 5,7,9,11 --> it means 7 = 7 works. and 7 = 9 works and 7 = 11 works.
 8 = ALL 5,6,7,8,9,10,11,12 --> all conversions work
 9 = 5,9 --> can
 10 = 6,10 --> can
 11 = 5,7,9,11 --> can
 12 = ALL 5,6,7,8,9,10,11,12 --> all conversions work


 ############################################################
 ############### Final Rules and Conclusions: ###############
 ############################################################
 
 ~~~~~~~~~~~~~~~~~~
 - Single pointer:
 ~~~~~~~~~~~~~~~~~
 ###Rule for implicit conversion:
 pointer to int = &var_const; // won't work. need const cast. actual int shouldn't be constant.
 this can be put as --> pointer to int = pointer to const int; // won't work. need const cast. actual int shouldn't be constant.
 ####Conclusion of explicit conversion using const_cast:
 we need explicit conversion (const_cast) to remove integer constness from a (single pointer to const int).
 But it will work SAFELY only if actual object is not constant as below
 
 int v = 10
 const int * ptr1 = &v1
 int * ptr2 = const_cast<int *>(ptr1)
 
 ~~~~~~~~~~~~~~~~~~
 - Double pointer:
 ~~~~~~~~~~~~~~~~~~
 ###Rule for implicit conversion:
 a) lvalue inner pointer has same type as rvalue inner pointer
 OR
 {
 b) pointer to constant pointer to constant int = any
 AND
 c) pointer to constant pointer to int = pointer to pointer to int
 }
 d) (outer most constant pointer) can be converted to (outer most non-constant pointer).
 e) (outer most non constant pointer) can be converted to (outer most constant pointer).
 ####Conclusion of explicit conversion using const_cast:
 1) we can remove constness of int. (SAFELY only if actual int is non constant)
 2) we can add constness to int.
 3) we can remove constness of inner pointer.
 4) we can add constness to inner pointer.
 

*/

int main(int argc, const char * argv[])
{
	int var = 10;
	const int var_const = 10;

	// pointer to int.
	int * ptr1 = &var; // address of var
	std::cout << "ptr1 =  " << ptr1 << std::endl; 		// 1) address of var
	std::cout << "*ptr1 =  " << *ptr1 << std::endl; 	// 2) value at address of var
	std::cout << "&ptr1 =  " << &ptr1 << std::endl; // address of ptr1 pointer

	// pointer to const int.
	//int * ptr2 = &var_const; 	// can't have a (pointer to non-const int) to point to const int.
	const int * ptr2 = &var_const;
	// *ptr2 = 20; 		// can't do this because ptr2 points to a constant int.
	//ptr2 = NULL; 		// can do this because ptr2 is not constant pointer

	// const pointer to int
	int * const ptr3 = &var;
	*ptr3 = 20; 		// can do this because ptr3 points to non constant int.
	//ptr3 = NULL; 		// can't do this because ptr3 is constant pointer.

	// const pointer to const int
	const int * const ptr4 = &var_const;
	//*ptr4 = 20; 		// can't change value because ptr4 points to constant int.
	//ptr4 = NULL; 		// can't do this because ptr4 is constant pointer.

	// pointer to (pointer to int)
	int ** ptr5 = &ptr1; // address of ptr1 pointer
	std::cout << "ptr5 = " << ptr5 << std::endl; 		// 1) address of ptr1 pointer
	std::cout << "*ptr5 = " << *ptr5 << std::endl; 		// 2) address of var
	std::cout << "**ptr5 = " << **ptr5 << std::endl; 	// 3) value at address of var
	std::cout << "&ptr5 = " << &ptr5 << std::endl; 		// address of ptr5
	//*ptr5 = NULL;		// can do this because ptr1 is non constant pointer. it means ptr1 = NULL;
	//ptr5 = NULL; 		// can do this because ptr5 is non constant pointer.

	// pointer to (pointer to const int)
	const int ** ptr6 = &ptr2;
	//**ptr6 = 10; 		// can't do this becuase ptr2 points to constant int.
	//*ptr6 = NULL; 	// can do this because ptr2 is non constant pointer. it means ptr2 = NULL;
	//ptr6 = NULL; 		// can do this because ptr6 is non constant pointer. it means ptr6 = NULL;
	// To avoid unused variable warning:
	std::cout << "**ptr6 = " << **ptr6 << std::endl;

	// pointer to (const pointer to int)
	int * const * ptr7 = &ptr3;
	//*ptr7 = NULL;		// can't do this because ptr3 is constant pointer. we can't do ptr3 = NULL;
	//ptr7 = NULL; 		// can do this because ptr7 is non constant pointer.
	**ptr7 = 100;		// can do this because ptr3 points to non constant int.

	// pointer to (const pointer to const int)
	const int * const * ptr8 = &ptr4;
	//*ptr8 = NULL;		// can't do this becuase ptr4 is constant pointer. we can't do ptr4 = NULL;
	//**ptr8 = 10;		// can't do this becaue ptr4 points to constant int.
	//ptr8 = NULL; 		// can do this because ptr8 is non constant pointer.
	// To avoid unused variable warning:
	std::cout << "**ptr8 = " << **ptr8 << std::endl;

	// const pointer to (pointer to int)
	int ** const ptr9 = &ptr1;
	//*ptr9 = NULL; 	// can do this because ptr1 is non constant pointer. it means ptr1 = NULL;
	**ptr9 = 20;		// can do this because ptr1 points to non constant int.
	//ptr9 = NULL; 		// can't do this because ptr9 is constant pointer.

	// const pointer to (pointer to const int)
	//int ** const ptr10 = &ptr2;	//can't do this because we need to point to constant int, instead of int.
	const int ** const ptr10 = &ptr2;
	//**ptr10 = 100; 		// can't do this because ptr2 points to constant int.
	// *ptr10 = NULL;		// can do this because ptr2 is non constant pointer. it means ptr2 = NULL;
	// ptr10 = NULL;		// can't do this because ptr10 is constant pointer.
	// To avoid unused variable warning:
	std::cout << "**ptr10 = " << **ptr10 << std::endl;

	// const pointer to (const pointer to int)
	int * const * const ptr11 = &ptr3;
	**ptr11 = 10;			// can do this because ptr3 points to non constant int.
	//*ptr11 = NULL;		// can't do this because ptr3 is constant pointer. it means ptr3 = NULL;
	//ptr11 = NULL;			// can't do this because ptr11 is constant.

	// const pointer to (const pointer to const int)
	const int * const * const ptr12 = &ptr4;
	//**ptr12 = 10;		// can't do this because ptr4 points to constant int.
	//*ptr12 = NULL;	// can't do this becuase ptr4 is constant pointer. it means ptr4 = NULL;
	//ptr12 = NULL;		// can't do this because ptr12 is constant pointer.
	// To avoid unused variable warning:
	std::cout << "**ptr12 = " << **ptr12 << std::endl;

	//  pointer to int =  pointer to int
	int * ptr13 = ptr1; 		// ptr13 will point to var
	// To avoid unused variable warning:
	std::cout << "*ptr13 = " << *ptr13 << std::endl;

	//  pointer to int =  pointer to const int
	//int * ptr14 = ptr2;		// can't do this. ptr14 can only point to int instead of const int.
	//see ConstCast. We can use const_cast here safely if actual object pointed to by ptr2 is not constant.
	
	
	// pointer to int = const pointer to int
	int * ptr15 = ptr3;			// ptr15 will point to var
	// To avoid unused variable warning:
	std::cout << "*ptr15 = " << *ptr15 << std::endl;

	//  pointer to int = const pointer to const int;
	//int * ptr16 = ptr4;		// can't do this. ptr16 can only point to int instead of const int.
	//see ConstCast. We can use const_cast here safely if actual object pointed to by ptr2 is not constant.

	// pointer to const int = pointer to int
	const int * ptr17 = ptr1;
	// To avoid unused variable warning:
	std::cout << "*ptr17 = " << *ptr17 << std::endl;

	// pointer to const int = pointer to const int
	const int * ptr18 = ptr2;
	// To avoid unused variable warning:
	std::cout << "*ptr18 = " << *ptr18 << std::endl;

	// pointer to const int = const pointer to int
	const int * ptr19 = ptr3;
	// To avoid unused variable warning:
	std::cout << "*ptr19 = " << *ptr19 << std::endl;

	// pointer to const int = const pointer to const int
	const int * ptr20 = ptr4;
	// To avoid unused variable warning:
	std::cout << "*ptr20 = " << *ptr20 << std::endl;

	return 0;
}
