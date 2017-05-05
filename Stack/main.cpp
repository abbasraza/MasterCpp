//
//  main.cpp
//  Stack
//
//  Created by abbas raza on 5/05/2017.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>
using namespace std;

const char SIZE = 40;

class Stack
{
private:
	char array[SIZE];
	char top;
public:
	Stack():top(-1)
	{
	}
	void push(char v)
	{
		if (!is_full())
		{
			array[++top] = v;
		}
	}
	char pop()
	{
		if (!is_empty())
		{
			return array[top--];
		}
		throw "Stack is empty. Pop failed";
	}
	bool is_full()
	{
		return top >= SIZE ? true : false;
	}
	bool is_empty()
	{
		return top == -1;
	}
	char get_top()
	{
		return top;
	}
};

int main(int argc, const char * argv[]) {
	Stack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(64);

	s.push(s.pop());

	cout << static_cast<int>(s.pop()) << endl;
	cout << static_cast<int>(s.pop()) << endl;
	cout << static_cast<int>(s.pop()) << endl;
	cout << static_cast<int>(s.pop()) << endl;
	cout << "Is stack empty? " << (s.is_empty() ? "YES":"NO") << '\n';

	// Generates Exception
	//cout << static_cast<int>(s.pop()) << endl;

	return 0;
}
