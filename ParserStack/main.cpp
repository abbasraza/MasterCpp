//
//  main.cpp
//  ParserStack
//
//  Created by abbas raza on 5/05/2017.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>
using namespace std;

const unsigned char SIZE = 40;

class Stack
{
private:
	char array[SIZE];
	signed char top;
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
		else
		{
			//FIXME
		}
	}
	char pop()
	{
		if (!is_empty())
		{
			return array[top--];
		}
		throw "Stack is empty. Pop failed"; // FIXME:
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

bool is_operator(char c)
{
	return (c == '*' || c == '/' || c == '+' || c == '-');
}

bool is_dm_operator(char c)
{
	return (c == '*' || c == '/');
}


bool is_value(char c)
{
	return (c >= '0' && c <= '9');
}

void resolve_op_recursively(Stack& e_stack, char in)
{
	if (e_stack.get_top() == 0) //stack has only 1 operand
	{
		e_stack.push(in);
	}
	else
	{
		char last_val = e_stack.pop();
		char last_op = e_stack.pop();
		if (is_dm_operator(in) && !is_dm_operator(last_op)) // 2 + 3 * 5 case only
		{
			e_stack.push(last_op);
			e_stack.push(last_val);
			e_stack.push(in);
		}
		else
		{
			char first_val = e_stack.pop();
			switch (last_op)
			{
				case '/':
					e_stack.push(first_val / last_val);
					break;
				case '*':
					e_stack.push(first_val * last_val);
					break;
				case '+':
					e_stack.push(first_val + last_val);
					break;
				case '-':
					e_stack.push(first_val - last_val);
					break;
				default:
					break;
			}
			resolve_op_recursively(e_stack, in);
		}
	}
}

void solve_expression_using_stack(Stack& e_stack, const char * input)
{
	while (*input)
	{
		char in = *input;
		if (in != ' ')
		{
			if (is_value(in))
			{
				e_stack.push(in - '0');
			}
			else if (is_operator(in))
			{
				resolve_op_recursively(e_stack, in);
			}
			else
			{
				cout << "unknow expression" << endl;
			}
		}
		input++;
	}

	while(e_stack.get_top())
	{
		char second_operand = e_stack.pop();
		char operator_ = e_stack.pop();
		
		switch (operator_)
		{
			case '+':
				e_stack.push(e_stack.pop() + second_operand);
				break;
			case '-':
				e_stack.push(e_stack.pop() - second_operand);
				break;
			case '*':
				e_stack.push(e_stack.pop() * second_operand);
				break;
			case '/':
				e_stack.push(e_stack.pop() / second_operand);
				break;
			default:
				cout << "unkown operand " << operator_ << endl;
		}
	}
}

void solve_expression_and_match_result(const char * input, char expected_result)
{
	Stack e_stack;
	char result;

	cout << "Expression: " << input;

	solve_expression_using_stack(e_stack, input);
	
	result = e_stack.pop();
	cout << " Got solution: " << static_cast<int>(result) << " Expected Solution: " <<  static_cast<int>(expected_result) << " Test: ";
	
	if (result == expected_result)
	{
		cout << "\nPASSED" << endl;
	}
	else
	{
		cout << "\nFAILED" << endl;
	}
}

int main(int argc, const char * argv[])
{
	const char * expressions[20] =
							{
								"5 / 5 + 3 - 6 * 2",
								"3 * 7 - 1 + 5 / 3",
								"3 * 5 - 4",
								"3 + 5 - 4",
								"2 / 6 * 3 / 2",
								"3 + 6 * 9 / 3 - 7",
								"9 - 5 / 5 * 2 + 6",
								"7 + 3 * 4 / 2 - 5 * 6",
								"4 * 5 + 3 - 4 / 2",
								"4 / 2 * 5 + 3 - 4",
								"5 + 3 * 4 / 2 - 3",
								"5 - 3 + 4 / 2",
								"5 * 3 / 2 - 2",
								"5 * 2 / 4 + 9 - 2"
							};

	char solutions[20] =
						{
							5 / 5 + 3 - 6 * 2,
							3 * 7 - 1 + 5 / 3,
							3 * 5 - 4,
							3 + 5 - 4,
							2 / 6 * 3 / 2,
							3 + 6 * 9 / 3 - 7,
							9 - 5 / 5 * 2 + 6,
							7 + 3 * 4 / 2 - 5 * 6,
							4 * 5 + 3 - 4 / 2,
							4 / 2 * 5 + 3 - 4,
							5 + 3 * 4 / 2 - 3,
							5 - 3 + 4 / 2,
							5 * 3 / 2 - 2,
							5 * 2 / 4 + 9 - 2
						};

	for (int i = 0; i < 20; ++i)
	{
		if (expressions[i])
		{
			solve_expression_and_match_result(expressions[i], solutions[i]);
		}
	}

	return 0;
}
