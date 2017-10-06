//
//  main.cpp
//  Stack2
//
//  Created by abbas raza on 6/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//


/* Purpose of this program:
 - Defining array lenght (const) in class.
 - 'static const' can be defined inside class. what about memory??
*/

#include <iostream>

class Stack
{
private:
	int top;
	static const int max = 10; // using static const so that we can use it in class functions.
	int s[max]; // we can say s[MAX] and define MAX on top of this file. But that will not comply with abstraction concept.
public:
	Stack(): top(-1)
	{
	}
	void push(int v)
	{
		if (top < max)
		{
			s[++top] = v;
		}
	}
	int pop()
	{
		if (top >= 0)
		{
			return s[top--];
		}
		return 211231231; // just fun
	}
};

int main()
{
	Stack s;
	
	std::cout << s.pop() << std::endl;
	
	s.push(11);
	s.push(2);
	
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	
	return 0;
	
}