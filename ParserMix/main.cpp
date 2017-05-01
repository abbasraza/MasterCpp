//
//  main.cpp
//  ParserMix
//  Parses and solves single digit arithmetic expressions like: 9*2+7-8/2-2 .
//  Code mix C/C++
//  Created by abbas raza on 1/05/2017.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node
{
	char val;
	char modified;
	struct node * next;
};

void print_expression(struct node * e)
{
	cout << "Printing arithmetic expression: ";
	while (e)
	{
		cout << e->val;
		e = e->next;
	}
	cout << endl;
}

int solve_sub_expression(struct node *e, char op)
{
	int first = e->modified ? e->val: atoi((const char *)&(e->val));
	int second = e->next->next->modified ? e->next->next->val : atoi((const char *)&(e->next->next->val));
	bool op_done = false;
	
	switch(op)
	{
		case '/':
			if (e->next->val == '/')
			{
				e->val = static_cast<char>(first / second);
				op_done = true;
			}
			break;
		case '*':
			if (e->next->val == '*')
			{
				e->val = static_cast<char>(first * second);
				op_done = true;
			}
			break;
		case '+':
			if (e->next->val == '+')
			{
				e->val = static_cast<char>(first + second);
				op_done = true;
			}
			break;
		case '-':
			if (e->next->val == '-')
			{
				e->val = static_cast<char>(first - second);
				op_done = true;
			}
			break;
		default:
			break;
	}
	
	if (op_done)
	{
		struct node *del1 = e->next;
		struct node *del2 = e->next->next;
		if (!e->modified)
		{
			e->modified = 1;
		}
		e->next = e->next->next->next;
		free(del1);
		free(del2);
		return 1;
	}

	return 0;
}

void solve_expression(struct node * e)
{
	char arithmetic_ops[4] = {'/', '*', '+', '-'};
	
	for (int i = 0; i < 4; ++i)
	{
		struct node * ptr = e;
		while (ptr && ptr->next && ptr->next->next)
		{
			if (!solve_sub_expression(ptr, arithmetic_ops[i]))
			{
				ptr = ptr->next->next;
			}
		}
	}
}

int main(int argc, const char * argv[]) {
	
	struct node * head = NULL;
	struct node * curr = NULL;
	cout << "Enter arithmetic expression to solve(! to end i.e 2*3!)\n : ";
	
	while(1)
	{
		char input;
		cin >> input;
		
		if (input == '!')
		{
			break;
		}

		if (head == NULL)
		{
			head = (struct node *)malloc(sizeof(struct node));
			head->val = input;
			head->next = NULL;
			curr = head;
		}
		else
		{
			struct node * n = (struct node *)malloc(sizeof(struct node));
			n->val = input;
			n->next = NULL;
			curr->next = n;
			curr = n;
		}
	}
	
	print_expression(head);
	
	solve_expression(head);
	
	cout << "Solution: " << static_cast<int>(head->val) << endl;
	
	print_expression(head);

    return 0;
}
