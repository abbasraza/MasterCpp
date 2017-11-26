//
//  main.cpp
//  ArithmeticExpressionParser
//
//  Created by abbas raza on 26/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Implement stack based arithmetic expression parser.
   No recursion at all.
 */

#include <iostream>

class Stack
{
private:
	int top;
	static const int max = 20;
	int s[max];
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
	int get_top()
	{
		return top;
	}
};

int valid_arithmetic_operator(int op)
{
	switch (op)
	{
		case '+':
		case '-':
		case '*':
		case '/':
			return 1;
		default:
			return 0;
	}
	return 0;
}

int is_mul_or_div(int op)
{
	switch (op)
	{
		case '*':
		case '/':
			return 1;
		default:
			return 0;
	}
	return 0;
}

int solve_simple_arithmetic_expression(int operand1, char operation, int operand2)
{
	switch (operation)
	{
		case '+':
			return operand2 + operand1;
		case '-':
			return operand2 - operand1;
		case '*':
			return operand2 * operand1;
		case '/':
			return operand2 / operand1;
		default:
			return 0;
			break;
	}
	return 0;
}

void solve_expression_and_match_result(const char * expression, int solution)
{
	Stack s;
	bool got_mul_div = 0;
	bool got_p_m = 0;
	
	for (int i = 0; i < strlen(expression); ++i)
	{
		char in = expression[i];
		if (in != ' ')
		{
			if (valid_arithmetic_operator(in))
			{
				got_mul_div = is_mul_or_div(in);
				if (!got_mul_div)
				{
					if (got_p_m)
					{
						int operand1 = s.pop();
						int last_operator = s.pop();
						int operand2 = s.pop();
						s.push(solve_simple_arithmetic_expression(operand1, last_operator, operand2));
					}
					got_p_m = 1;
				}
				s.push(in);
			}
			else
			{
				s.push(expression[i] - '0');
				if (got_mul_div)
				{
					int operand1 = s.pop();
					int last_operator = s.pop();
					int operand2 = s.pop();
					s.push(solve_simple_arithmetic_expression(operand1, last_operator, operand2));
					got_mul_div = 0;
				}
			}
		}
	}
	
	int operand1 = s.pop();
	int last_operator = s.pop();
	int operand2 = s.pop();
	s.push(solve_simple_arithmetic_expression(operand1, last_operator, operand2));
	
	
	std::cout << "My solution: " << s.pop() << " actual: " << solution << std::endl;
}

int main()
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
		"5 * 2 / 4 + 9 - 2",
		"2 - 5 + 2 - 5 + 4 + 4 + 2",
		"2 - 4"
	};
	
	int solutions[20] =
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
		5 * 2 / 4 + 9 - 2,
		2 - 5 + 2 - 5 + 4 + 4 + 2,
		2 - 4
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

