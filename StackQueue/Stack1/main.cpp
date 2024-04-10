//
//  main.cpp
//  Stack1
//
//  Created by abbas raza on 5/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of array in class data.
*/

#include <iostream>

class Stack
{
private:
	int top;
	int s[10];  // how to define/use a constant number in class???? i.e for lenght of array
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