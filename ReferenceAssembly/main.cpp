//
//  main.cpp
//  ReferenceAssembly
//
//  Created by abbas raza on 7/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - To see difference between pointer and reference/alias.
 - Pointer and reference have only 1 differece, that is a pointer can be redirected but reference
   cannot be redirected.
 - Other than that, both work exactly same at low level (in assembly).
 - How pointer works at low level.
 - How pointer redirection works at low level.
 - How alias works at low level.
 - Alias/reference = pointer = 8 Byte space in memory to hold address. (on 64 bit system)
*/

#include <iostream>

/* Change value of int variable 'var' via pointer 'ptr_to_var'.
 What happens in assembly:
 1) reserve space for 'var' on stack (4 Bytes).
 2) store address of space reserved for 'var' in step1) inside register rax.
 3) store 'var' on stack at space reserve in step 1)
 4) reserve a space for pointer 'ptr_to_var' on stack (8 bytes on 64bit machine)
 5) store address of 'var' from step 2) in space reserved for 'ptr_to_var' in step 4).
 6) Now when we assign a value VAL to 'var' via 'ptr_to_var':
	i) fetch address stored inside 'ptr_to_var'.
    ii) store VAL inside that address.
*/
int usage_of_pointer1()
{
	/*
	 ReferenceAssembly`usage_of_pointer1:
	 0x100000f20 <+0>:  pushq  %rbp
	 0x100000f21 <+1>:  movq   %rsp, %rbp
	 0x100000f24 <+4>:  leaq   -0x4(%rbp), %rax
	 0x100000f28 <+8>:  movl   $0xa, -0x4(%rbp)
	 0x100000f2f <+15>: movq   %rax, -0x10(%rbp)
	 0x100000f33 <+19>: movq   -0x10(%rbp), %rax
	 0x100000f37 <+23>: movl   $0x14, (%rax)
	 0x100000f3d <+29>: movq   -0x10(%rbp), %rax
	 0x100000f41 <+33>: movl   (%rax), %eax
	 0x100000f43 <+35>: popq   %rbp
	 0x100000f44 <+36>: retq
	 */
	
	int var = 10;
	int * ptr_to_var = &var;
	
	*ptr_to_var = 20;
	
	return *ptr_to_var;
}

/* Change value of int variable 'var1' via pointer 'ptr_to_var'. Then re-direct 'ptr_to_var' to 'var2'
 What happens in assembly:
 1) reserve space for 'var1' on stack (4 Bytes).
 2) reserve space for 'var2' on stack (4 Bytes).
 3) store address of space reserved for 'var1' in step1) inside register rcx.
 4) store address of space reserved for 'var2' in step2) inside register rax.
 5) store 'var1' on stack at space reserve in step 1)
 6) store 'var2' on stack at space reserve in step 2)
 7) reserve a space for pointer 'ptr_to_var' on stack (8 bytes on 64bit machine)
 8) store address of 'var1' from step 3) in space reserved for 'ptr_to_var' in step 7).
 9) Now when we assign a value VAL to 'var1' via 'ptr_to_var':
	i) fetch address stored inside 'ptr_to_var'.
    ii) store VAL inside that address.
 10) Now we will redirect 'ptr_to_var' to 'var2'
    i) store address of 'var2' from step 4) in space reserved for 'ptr_to_var' in step 7).
 */

int usage_of_pointer2()
{
	/*
	 ReferenceAssembly`usage_of_pointer2:
	 0x100000f10 <+0>:  pushq  %rbp
	 0x100000f11 <+1>:  movq   %rsp, %rbp
	 0x100000f14 <+4>:  leaq   -0x8(%rbp), %rax
	 0x100000f18 <+8>:  leaq   -0x4(%rbp), %rcx
	 0x100000f1c <+12>: movl   $0xa, -0x4(%rbp)
	 0x100000f23 <+19>: movl   $0x9, -0x8(%rbp)
	 0x100000f2a <+26>: movq   %rcx, -0x10(%rbp)
	 0x100000f2e <+30>: movq   -0x10(%rbp), %rcx
	 0x100000f32 <+34>: movl   $0x14, (%rcx)
	 0x100000f38 <+40>: movq   %rax, -0x10(%rbp)
	 0x100000f3c <+44>: movq   -0x10(%rbp), %rax
	 0x100000f40 <+48>: movl   (%rax), %eax
	 0x100000f42 <+50>: popq   %rbp
	 0x100000f43 <+51>: retq
	 */

	int var1 = 10;
	int var2 = 9;
	int * ptr_to_var = &var1;
	
	*ptr_to_var = 20;
	
	ptr_to_var = &var2;
	
	return *ptr_to_var;
}


/* Change value of int variable 'var' via alias 'alias_of_var'.
 What happens in assembly:
 1) reserve space for 'var' on stack (4 Bytes).
 2) store address of space reserved for 'var' in step1) inside register rax.
 3) store 'var' on stack at space reserve in step 1)
 4) reserve a space for alias 'alias_of_var' on stack (8 bytes on 64bit machine)
 5) store address of 'var' from step 2) in space reserved for 'alias_of_var' in step 4).
 6) Now when we assign a value VAL to 'var' via 'alias_of_var':
	i) fetch address stored inside 'alias_of_var'.
    ii) store VAL inside that address.
*/
int usage_of_alias()
{
	/*
	 ReferenceAssembly`usage_of_alias:
	 0x100000f50 <+0>:  pushq  %rbp
	 0x100000f51 <+1>:  movq   %rsp, %rbp
	 0x100000f54 <+4>:  leaq   -0x4(%rbp), %rax
	 0x100000f58 <+8>:  movl   $0xa, -0x4(%rbp)
	 0x100000f5f <+15>: movq   %rax, -0x10(%rbp)
	 0x100000f63 <+19>: movq   -0x10(%rbp), %rax
	 0x100000f67 <+23>: movl   $0x14, (%rax)
	 0x100000f6d <+29>: movq   -0x10(%rbp), %rax
	 0x100000f71 <+33>: movl   (%rax), %eax
	 0x100000f73 <+35>: popq   %rbp
	 0x100000f74 <+36>: retq
	 */

	//pushq  %rbp
	//movq   %rsp, %rbp
	
	/*
	*                       --------------------------------------------------------------------
	* rbp = rsp = --> 0x80  |                             |0x84|								| 0x87
	*                       --------------------------------------------------------------------
	*                 0x78  |                             |0x7C|                                | 0x7F
	*                       --------------------------------------------------------------------
    */
	
	//leaq   -0x4(%rbp), %rax
	// rax = 0x80 - 0x4 = 0x7C

	int var = 10;				// movl   $0xa, -0x4(%rbp)
	/*
	 *                       --------------------------------------------------------------------
	 * rbp = rsp = --> 0x80  |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                 0x78  |                             |0x7C| 0xa    0x00    0x00    0x00   | 0x7F
	 *                       --------------------------------------------------------------------
	 */

	

	int& alias_of_var = var;		// movq   %rax, -0x10(%rbp)
	// alias_of_var will basically contains address of var.
	// rax contains address of var on stack.
	// store rax on stack. so alias_of_var on stack = rax = address of var
	
	/*
	 *                       --------------------------------------------------------------------
	 * rbp = rsp = --> 0x80  |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                 0x78  |                             |0x7C| 0xa    0x00    0x00    0x00   | 0x7F
	 *                       --------------------------------------------------------------------
	 *                       --------------------------------------------------------------------
	 *                 0x70  |                          0x7C                                    | 0x7F
	 *                       --------------------------------------------------------------------
	 */

	
	alias_of_var = 20;			// 1) movq   -0x10(%rbp), %rax      2) movl   $0x14, (%rax)
	// store 20 at address of var.
	
	/*
	 *                       --------------------------------------------------------------------
	 * rbp = rsp = --> 0x80  |                             |0x84|								| 0x87
	 *                       --------------------------------------------------------------------
	 *                 0x78  |                             |0x7C| 0x14    0x00    0x00    0x00   | 0x7F
	 *                       --------------------------------------------------------------------
	 *                       --------------------------------------------------------------------
	 *                 0x70  |                              0x7C                                 | 0x7F
	 *                       --------------------------------------------------------------------
	 */


	return alias_of_var;			// 1) movq   -0x10(%rbp), %rax      2) movl   (%rax), %eax
	
	//popq   %rbp
	//retq
}

int main(int argc, const char * argv[])
{
	usage_of_alias();
	usage_of_pointer1();
	usage_of_pointer2();

	return 0;
}
