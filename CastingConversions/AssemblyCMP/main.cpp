//
//  main.cpp
//  AssemblyCMP
//
//  Created by abbas raza on 15/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/*
 Purpose of this program: 
 - How comparison works
	if (number1 < number2)
 - It uses cmp instruction. It subtract one operand from other. how?
 
 - How assembly instruction cmp sets CF(Carry Flag) and SF(Sign Flag). How
 
 Breakpoint hit after cmp:
 
 Breakpoint 2, 0x0000000000400509 in main ()
 (gdb) disassemble
 Dump of assembler code for function main:
 0x00000000004004f6 <+0>:     push   %rbp
 0x00000000004004f7 <+1>:     mov    %rsp,%rbp
 0x00000000004004fa <+4>:     movb   $0x4,-0x2(%rbp)
 0x00000000004004fe <+8>:     movb   $0x5,-0x1(%rbp)
 0x0000000000400502 <+12>:    movzbl -0x2(%rbp),%eax
 0x0000000000400506 <+16>:    cmp    -0x1(%rbp),%al
 => 0x0000000000400509 <+19>:    jae    0x40050f <main+25>
 0x000000000040050b <+21>:    movb   $0x0,-0x2(%rbp)
 0x000000000040050f <+25>:    pop    %rbp
 0x0000000000400510 <+26>:    retq
 End of assembler dump.
 Register dump after cmp has been executed:
 
 (gdb) info reg
 rax            0x4  4
 rbx            0x0  0
 rcx            0x0  0
 rdx            0x7fffffffe608   140737488348680
 rsi            0x7fffffffe5f8   140737488348664
 rdi            0x1  1
 rbp            0x7fffffffe510   0x7fffffffe510
 rsp            0x7fffffffe510   0x7fffffffe510
 r8             0x7ffff7dd4dd0   140737351863760
 r9             0x7ffff7de99d0   140737351948752
 r10            0x833    2099
 r11            0x7ffff7a2f950   140737348041040
 r12            0x400400 4195328
 r13            0x7fffffffe5f0   140737488348656
 r14            0x0  0
 r15            0x0  0
 rip            0x400509 0x400509 <main+19>
 eflags         0x297    [ CF PF AF SF IF ]
 cs             0x33 51
 ss             0x2b 43
 ds             0x0  0
 es             0x0  0
 fs             0x0  0
 gs             0x0  0
 (gdb)
 So we can see that after cmp has been executed, both CF=1, SF=1.
 
 
 
 4 - 5
 
 1st operand = 4 = 0000 0100
 2nd operand = 5 = 0000 0101
 
 So we have to perform
 
 1st operand
 - 2nd operand
 --------------
 
 
 7654 3210 <-- Bit number
 0000 0100
 - 0000 0101
 ------------
 
 Lets start.
 
 Bit 0 of 1st operand = 0
 Bit 0 of 2nd operand = 1
 
 so
 
 0
 - 1
 ===
 ?
 to do this,
 
 let's borrow a 1 from left side of bit 0 of 1st operand.
 
 so we see bit 2 of 1st operand is 1.
 
 when bit 2 is = 1, it means 4.
 
 we know that we can write 4 as 2 + 2. So we can write 4 as two 2s.
 
 7654 3210 <-- Bit number
 1
 1
 0000 0000
 - 0000 0101
 ------------
 So in above step, we have written bit 4 of 1st operand as two 2s (two 1 on top of bit 2 of 1st operand.)
 
 Now again as we know, a 2 can be written as two 1s. So we borrow one 1 from bit 1 of 1st operand and write two 1s on bit 0 of 1st operand.
 
 7654 3210 <-- Bit number
 1
 11
 0000 0000
 - 0000 0101
 ------------
 Now we are ready to perform subtraction on bit 0 and bit 1.
 
 7654 3210 <-- Bit number
 1
 11
 0000 0000
 - 0000 0101
 ------------
 11
 So after solving bit 0 and bit 1, lets see bit 2.
 
 We again see same problem.
 
 Bit 2 of 1st operand = 0
 
 Bit 2 of 2nd operand = 1
 
 to do this, let's borrow a 1 from left side of bit 2 of 1st operand.
 
 8 7654 3210 <-- Bit number
 1
 11
 1 0000 0000
 - 0000 0101
 ------------
 11
 Now you see, bit 8 of 1st operand is 1. We have borrowed this 1.
 
 At this stage, carry flag will be set. So CF=1.
 
 Now, if bit 8 is 1, it means 256.
 
 256 = 128 + 128
 
 if bit 7 is 1, it means 128. We can rewrite as
 
 8 7654 3210 <-- Bit number
 1       1
 1      11
 0000 0000
 - 0000 0101
 ------------
 11
 As previously, we can re-write it as:
 
 8 7654 3210 <-- Bit number
 1      1
 11     11
 0000 0000
 - 0000 0101
 ------------
 11
 As previously, we can re-write it as:
 
 8 7654 3210 <-- Bit number
 1     1
 111    11
 0000 0000
 - 0000 0101
 ------------
 11
 As previously, we can re-write it as:
 
 8 7654 3210 <-- Bit number
 1    1
 1111   11
 0000 0000
 - 0000 0101
 ------------
 11
 As previously, we can re-write it as:
 
 8 7654 3210 <-- Bit number
 1  1
 1111 1 11
 0000 0000
 - 0000 0101
 ------------
 11
 As previously, we can re-write it as:
 
 8 7654 3210 <-- Bit number
 1 1
 1111 1111
 0000 0000
 - 0000 0101
 ------------
 11
 At last we can solve this.
 
 Subtracting 2nd operand from all above it will give
 
 8 7654 3210 <-- Bit number
 1 1
 1111 1111
 0000 0000
 - 0000 0101
 ------------
 1111 1111
 
 
 So result = 1111 1111
 Notice, sign bit in result = bit 7 = 1
 
 so sign flag will be set. i.e SF=1
 
 And therefore SF=1, CF=1 after 4 - 5

*/

#include <iostream>

int main(int argc, const char * argv[])
{
	unsigned char number1 = 4;
	unsigned char number2 = 5;
	
	if (number1 < number2)
	{
		number1 = 0;
	}
	return 0;
}
