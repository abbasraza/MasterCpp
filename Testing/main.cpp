//
//  main.cpp
//  Testing
//
//  Created by abbas raza on 16/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//
#include <iostream>

/*
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

*/


int main()
{
	int v = 10;
	int * ptr1 = &v;
	const int * ptr2 = &v;
	int * const ptr3 = &v;
	const int * const ptr4 = &v;
	
	int ** ptr5 = &ptr1;
	const int ** ptr6 = &ptr2;
	int * const * ptr7 = &ptr3;
    const int * const * ptr8 = &ptr4;
	int ** const ptr9 = &ptr1;
	const int ** const ptr10 = &ptr2;
	int * const * const ptr11 = &ptr3;
	const int * const * const ptr12 = &ptr4;

	int * const * p2 = &ptr3;
	int ** p3 = const_cast<int **>(p2);
	std::cout << "p3 = " << p3 << std::endl;
	std::cout << "p2 = " << p2 << std::endl;
	std::cout << "&ptr3 = " << &ptr3 << std::endl;

	
	
#if 0
#define PTR  const int * const * const
	//6
	PTR ptrt1 = const_cast<PTR>(ptr5); // added constness to inner ptr
	PTR ptrt2 = const_cast<PTR>(ptr6); // removed constness from int, added constness to inner ptr
	PTR ptrt3 = const_cast<PTR>(ptr7); // removed constness from innter ptr
	PTR ptrt4 = const_cast<PTR>(ptr8); // removed constness from innter ptr, added constness to int
	PTR ptrt5 = const_cast<PTR>(ptr9); // removed constness from innter ptr, added constness to int
	PTR ptrt6 = const_cast<PTR>(ptr10); // removed constness from innter ptr
	PTR ptrt7 = const_cast<PTR>(ptr11); // removed constness from innter ptr, added constness to int
	PTR ptrt8 = const_cast<PTR>(ptr12); // removed constness from innter ptr
#endif
	return 1;
}
