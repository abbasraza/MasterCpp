//
//  main.cpp
//  FunctionOverride
//
//  Created by abbas raza on 3/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of function overriding. Polymorphism (many same) How to improve existing classes (functions).

  -------
 | Stack |
  -------
	 ^
	 |
	 |
  --------
 | Stack2 |
  --------

 - Overriding is done by using same function name, return and parameters.
 - Scope resolution. Compiler won't know which class's function we are calling, i.e of B or D.
   so in D we do B::function();
 - Can ctor be overriden? NO. doesn't make any sense.
 - Early/Compile-time/static function call binding? TODO
*/

#include <iostream>

class Stack
{
protected:
	int top;
	static const int max = 10; // using static const so that we can use it in class functions.
	int s[max]; // we can say s[MAX] and define MAX on top of this file. But that will not comply with abstraction concept.
public:
	Stack(): top(-1)
	{
	}
	void push(int v)
	{
		s[++top] = v;
	}
	int pop()
	{
		return s[top--];
	}
};

class Stack2 : public Stack
{
public:
	void push(int v)
	{
		if (top < max)
		{
			Stack::push(v); // push of Stack class
		}
		else
		{
			std::cout << "Errr Stack full" << std::endl;
		}
	}
	int pop()
	{
		if (top > -1)
		{
			return Stack::pop();
		}
		else
		{
			std::cout << "Errr Stack empty" << std::endl;
			exit(1);
		}
	}
};

int main()
{
	Stack s1;
	//Stack::push(&s1, 10); // TODO: only static member function of class can be called without dot operator.

	s1.push(11);
	s1.push(2);

	std::cout << s1.pop() << std::endl;
	std::cout << s1.pop() << std::endl;
	std::cout << s1.pop() << std::endl; // no Errr. Stack's pop called

	Stack2 s2;
	s2.pop(); // Stack2's pop called.

	return 0;
}