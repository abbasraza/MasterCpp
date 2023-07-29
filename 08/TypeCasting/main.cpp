//
//  main.cpp
//  TypeCasting
//
//  Created by abbas raza on 14/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - To find out difference between c-style cast, static_cast and reinterpret_cast.
 - To find out usages of these casts. C-style cast is used here for just comparison. Otherwise not allowed.
 - C-Style and reinterpret have same assembly in this case.
 - static_cast has 1 extra pointer stored to void * and then from void *.
*/

#include <iostream>

/*
	|0x84|, |0x7C| represent addresses.
	bp = frame pointer.
	sp = stack pointer.
	rsp = register containing stack pointer.
	rbp = register containing frame pointer.
	1 stack, many frames.
 */

void pointer_reinterpret_cast()
{
	/*
	 *	Assembly instruction:
	 *		 pushq  %rbp			--> pushed frame pointer (%rbp) to stack
	 *		 movq   %rsp, %rbp	    --> copied stack pointer (%rsp) into %rbp
	 *
	 * Register and stack memory state:
	 *
	 *                   --------------------------------------------------------------------
	 * rbp = rsp = 0x80  |                             |0x84|								| 0x87
	 *                   --------------------------------------------------------------------
	 */
	
	/*
	 *	Assembly instruction:
	 *		 leaq   -0x8(%rbp), %rax ---> load effective address quad. load address (not value) of rbp - 8 into rax.
	 *
	 * Register and stack memory state:
	 *
	 *                       --------------------------------------------------------------------
	 * rbp = rsp = --> 0x80  |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   |                             |0x7C|                               | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 * rax = 0x78
	 */
	
	unsigned int x1 = 1;
	/*
	 *	Assembly instruction:
	 *		 movl   $0x1, -0x4(%rbp)
	 *
	 * Register and stack memory state:
	 *
	 *                       --------------------------------------------------------------------
	 * rbp = rsp = --> 0x80  |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   |                             |0x7C| 0x01    0x00    0x00    0x00  | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 * rax = 0x78
	 */
	
	unsigned int x2 = 0xf;
	/*
	 *	Assembly instruction:
	 *		 movl   $0xf, -0x8(%rbp)  --> creating new space on stack i.e pushing
	 *
	 *
	 * Register and stack memory state:
	 *
	 *                       --------------------------------------------------------------------
	 * rbp = rsp = --> 0x80  |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   | 0x0F   0x00   0x00   0x00   |0x7C| 0x01    0x00    0x00    0x00  | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 * rax = 0x78
	 */
	
	unsigned char * p2 = reinterpret_cast<unsigned char *>(&x2);
	/*
	 *	Assembly instruction:
	 *		movq   %rax, -0x10(%rbp) --> creating new space on stack i.e pushing
	 *
	 *
	 * Register and stack memory state:
	 *
	 *                       --------------------------------------------------------------------
	 * rbp = rsp =    0x80   |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   | 0x0F   0x00   0x00   0x00   |0x7C| 0x01    0x00    0x00    0x00  | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 * rax = 0x78
	 *
	 *                       --------------------------------------------------------------------
	 *                0x70   | 0x78   0x00   0x00   0x00          0x00    0x00    0x00    0x00  | 0x77
	 *                       --------------------------------------------------------------------
	 *                 ^
	 *                 | bp - 0x10
	 *
	 *
	 */
	
	
	*p2 = 2;
	/*
	 *	Assembly instruction:
	 *		movq   -0x18(%rbp), %rax
	 *		movb   $0x2, (%rax)
	 *
	 * Register and stack memory state:
	 *
	 * rax = 0x78
	 *                       --------------------------------------------------------------------
	 * rbp = rsp =    0x80   |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   | 0x02   0x00   0x00   0x00   |0x7C| 0x01    0x00    0x00    0x00  | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 *
	 *
	 *                       --------------------------------------------------------------------
	 *                0x70   | 0x78   0x00   0x00   0x00          0x00    0x00    0x00    0x00  | 0x77
	 *                       --------------------------------------------------------------------
	 *                 ^
	 *                 | bp - 0x10
	 *
	 *
	 *                       --------------------------------------------------------------------
	 *                0x68   | 0x78   0x00   0x00   0x00          0x00    0x00    0x00    0x00  | 0x6F
	 *                       --------------------------------------------------------------------
	 *                 ^
	 *                 | bp - 0x18
	 *
	 */
}

/*
	|0x84|, |0x7C| represent addresses.
	bp = frame pointer.
	sp = stack pointer.
	rsp = register containing stack pointer.
	rbp = register containing frame pointer.
	1 stack, many frames.
 */

void pointer_static_cast()
{
	/*
	 *	Assembly instruction:
	 *		 pushq  %rbp			--> pushed frame pointer (%rbp) to stack
	 *		 movq   %rsp, %rbp	    --> copied stack pointer (%rsp) into %rbp
	 *
	 * Register and stack memory state:
	 *
	 *                   --------------------------------------------------------------------
	 * rbp = rsp = 0x80  |                             |0x84|								| 0x87
	 *                   --------------------------------------------------------------------
	 */
	
	/*
	 *	Assembly instruction:
	 *		 leaq   -0x8(%rbp), %rax ---> load effective address quad. load address (not value) of rbp - 8 into rax.
	 *
	 * Register and stack memory state:
	 *
	 *                       --------------------------------------------------------------------
	 * rbp = rsp = --> 0x80  |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   |                             |0x7C|                               | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 * rax = 0x78
	 */
	
	unsigned int x1 = 1;
	/*
	 *	Assembly instruction:
	 *		 movl   $0x1, -0x4(%rbp)
	 *
	 * Register and stack memory state:
	 *
	 *                       --------------------------------------------------------------------
	 * rbp = rsp = --> 0x80  |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   |                             |0x7C| 0x01    0x00    0x00    0x00  | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 * rax = 0x78
	 */
	
	
	unsigned int x2 = 0xf;
	/*
	 *	Assembly instruction:
	 *		 movl   $0xf, -0x8(%rbp)  --> creating new space on stack i.e pushing
	 *
	 *
	 * Register and stack memory state:
	 *
	 *                       --------------------------------------------------------------------
	 * rbp = rsp = --> 0x80  |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   | 0x0F   0x00   0x00   0x00   |0x7C| 0x01    0x00    0x00    0x00  | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 * rax = 0x78
	 */
	
	
	void * p1 = &x2;
	/*
	 *	Assembly instruction:
	 *		movq   %rax, -0x10(%rbp) --> creating new space on stack i.e pushing
	 *
	 *
	 * Register and stack memory state:
	 *
	 *                       --------------------------------------------------------------------
	 * rbp = rsp =    0x80   |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   | 0x0F   0x00   0x00   0x00   |0x7C| 0x01    0x00    0x00    0x00  | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 * rax = 0x78
	 *
	 *                       --------------------------------------------------------------------
	 *                0x70   | 0x78   0x00   0x00   0x00          0x00    0x00    0x00    0x00  | 0x77
	 *                       --------------------------------------------------------------------
	 *                 ^
	 *                 | bp - 0x10
	 *
	 *
	 */
	
	unsigned char * p2 = static_cast<unsigned char *>(p1);
	/*
	 *	Assembly instruction:
	 *		movq   -0x10(%rbp), %rax ---> does it move rbp - 0x10 = 0x70 into rax or value at address 0x70 ?
	 *									  It moves value inside address 0x70 into rax. i.e 0x78.
	 *		movq   %rax, -0x18(%rbp)
	 *
	 * Register and stack memory state:
	 *
	 * rax = 0x78
	 *                       --------------------------------------------------------------------
	 * rbp = rsp =    0x80   |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   | 0x0F   0x00   0x00   0x00   |0x7C| 0x01    0x00    0x00    0x00  | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 *
	 *
	 *                       --------------------------------------------------------------------
	 *                0x70   | 0x78   0x00   0x00   0x00          0x00    0x00    0x00    0x00  | 0x77
	 *                       --------------------------------------------------------------------
	 *                 ^
	 *                 | bp - 0x10
	 *
	 *
	 *                       --------------------------------------------------------------------
	 *                0x68   | 0x78   0x00   0x00   0x00          0x00    0x00    0x00    0x00  | 0x6F
	 *                       --------------------------------------------------------------------
	 *                 ^
	 *                 | bp - 0x18
	 *
	 */
	
	
	*p2 = 2;
	/*
	 *	Assembly instruction:
	 *		movq   -0x10(%rbp), %rax
	 *		movb   $0x2, (%rax)	---> place 2 inside the address which rax contains. not in rax register. i.e place 2 inside 0x78.
	 *
	 *
	 * Register and stack memory state:
	 *
	 * rax = 0x78
	 *                       --------------------------------------------------------------------
	 * rbp = rsp =    0x80   |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   | 0x02   0x00   0x00   0x00   |0x7C| 0x01    0x00    0x00    0x00  | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 *
	 *
	 *                       --------------------------------------------------------------------
	 *                0x70   | 0x78   0x00   0x00   0x00          0x00    0x00    0x00    0x00  | 0x77
	 *                       --------------------------------------------------------------------
	 *                 ^
	 *                 | bp - 0x10
	 *
	 *
	 */
}


/*
	|0x84|, |0x7C| represent addresses.
	bp = frame pointer.
	sp = stack pointer.
	rsp = register containing stack pointer.
	rbp = register containing frame pointer.
	1 stack, many frames.
 */
void pointer_c_style()
{
	/*
	 *	Assembly instruction:
	 *		 pushq  %rbp			--> pushed frame pointer (%rbp) to stack
	 *		 movq   %rsp, %rbp	    --> copied stack pointer (%rsp) into %rbp
	 *
	 * Register and stack memory state:
	 *
	 *                   --------------------------------------------------------------------
	 * rbp = rsp = 0x80  |                             |0x84|								| 0x87
	 *                   --------------------------------------------------------------------
	 */
	
	/*
	 *	Assembly instruction:
	 *		 leaq   -0x8(%rbp), %rax ---> load effective address quad. load address (not value) of rbp - 8 into rax.
	 *
	 * Register and stack memory state:
	 *
	 *                       --------------------------------------------------------------------
	 * rbp = rsp = --> 0x80  |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   |                             |0x7C|                               | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 * rax = 0x78
	 */
	
	
	unsigned int x1 = 1;
	/*
	 *	Assembly instruction:
	 *		 movl   $0x1, -0x4(%rbp)
	 *
	 * Register and stack memory state:
	 *
	 *                       --------------------------------------------------------------------
	 * rbp = rsp = --> 0x80  |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   |                             |0x7C| 0x01    0x00    0x00    0x00  | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 * rax = 0x78
	 */
	
	unsigned int x2 = 0xf;
	/*
	 *	Assembly instruction:
	 *		 movl   $0xf, -0x8(%rbp)  --> creating new space on stack i.e pushing
	 *
	 *
	 * Register and stack memory state:
	 *
	 *                       --------------------------------------------------------------------
	 * rbp = rsp = --> 0x80  |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   | 0x0F   0x00   0x00   0x00   |0x7C| 0x01    0x00    0x00    0x00  | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 * rax = 0x78
	 */
	
	
	unsigned char * ptr  = (unsigned char *)(&x2);
	/*
	 *	Assembly instruction:
	 *		movq   %rax, -0x10(%rbp) --> creating new space on stack i.e pushing
	 *
	 *
	 * Register and stack memory state:
	 *
	 *                       --------------------------------------------------------------------
	 * rbp = rsp =    0x80   |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   | 0x0F   0x00   0x00   0x00   |0x7C| 0x01    0x00    0x00    0x00  | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 * rax = 0x78
	 *
	 *                       --------------------------------------------------------------------
	 *                0x70   | 0x78   0x00   0x00   0x00          0x00    0x00    0x00    0x00  | 0x77
	 *                       --------------------------------------------------------------------
	 *                 ^
	 *                 | bp - 0x10
	 *
	 *
	 */
	
	*ptr = 2;
	/*
	 *	Assembly instruction:
	 *		movq   -0x10(%rbp), %rax
	 *		movb   $0x2, (%rax)	---> place 2 inside the address which rax contains. not in rax register. i.e place 2 inside 0x78.
	 *
	 *
	 * Register and stack memory state:
	 *
	 * rax = 0x78
	 *                       --------------------------------------------------------------------
	 * rbp = rsp =    0x80   |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                0x78   | 0x02   0x00   0x00   0x00   |0x7C| 0x01    0x00    0x00    0x00  | 0x7F
	 *                       --------------------------------------------------------------------
	 *                 ^                                     ^
	 *                 | rbp - 8                             | rbp - 4
	 *
	 *
	 *
	 *                       --------------------------------------------------------------------
	 *                0x70   | 0x78   0x00   0x00   0x00          0x00    0x00    0x00    0x00  | 0x77
	 *                       --------------------------------------------------------------------
	 *                 ^
	 *                 | bp - 0x10
	 *
	 *
	 */
}

int main()
{
	pointer_c_style();
	pointer_static_cast();
	pointer_reinterpret_cast();
	
	return 1;
}