//
//  main.cpp
//  Parser
//
//  Created by abbas raza on 1/05/2017.
//  Copyright © 2017 Self. All rights reserved.
//

// parse.cpp
// evaluates arithmetic expressions composed of 1-digit numbers
#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 80;
const int MAX = 40;
////////////////////////////////////////////////////////////////
class Stack
{
private:
	char st[MAX];
	int top;
public:
	Stack()
	{
		top = 0;
	}
	void push(char var)
	{
		st[++top] = var;
	}
	char pop()
	{
		return st[top--];
	}
	int gettop()
	{
		return top;
	}
};

class express
{
private:
	Stack s;
	char * pStr;
	int len;
public:
	express(char * ptr)
	{
		pStr = ptr;
		len = static_cast<int>(strlen(pStr));
	}
	void parse();
	int solve();
};

void express::parse()
{
	char ch;
	char lastval;
	char lastop;
	for(int j=0; j<len; j++)
	{
		ch = pStr[j];
		if (ch != ' ')
		{
			if(ch>='0' && ch<='9')
				s.push(ch - '0');
			else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				if(s.gettop()==1)
					s.push(ch);
				else {
					lastval = s.pop();
					lastop = s.pop();
					//if this is * or / AND last operator was + or -
					if( (ch=='*' || ch=='/') && (lastop=='+' || lastop=='-') )
					{
						s.push(lastop);
						s.push(lastval);
					}
					else {
						switch(lastop)
						{
							default:  cout << "\nUnknown oper"; exit(1);
							case '+': s.push(s.pop() + lastval); break;
							case '-': s.push(s.pop() - lastval); break;
							case '*': s.push(s.pop() * lastval); break;
							case '/': s.push(s.pop() / lastval); break;
						}  //end switch
					}  //end else, in all other cases
					s.push(ch);              //put current op on stack
				}  //end else, not first operator
			}  //end else if, it’s an operator
			else                           //not a known character
			{ cout << "\nUnknown input character"; exit(1); }
		}
	}  //end for
}  //end parse()

int express::solve()
{
	char lastval;
	while(s.gettop() > 1)
	{
		lastval = s.pop();
		char t = s.pop();
		switch( t )
		{
			case '+': s.push(s.pop() + lastval); break;
			case '-': s.push(s.pop() - lastval); break;
			case '*': s.push(s.pop() * lastval); break;
			case '/': s.push(s.pop() / lastval); break;
			default:  cout << "\nUnknown operator " << t; exit(1);
		}  //end switch
	}  //end while
	return int( s.pop() );            //last item on stack is ans
}  //end solve()

int main()
{
	char ans;                         //’y’ or ‘n’
	char string[LEN];                 //input string from user
	cout << "\nEnter an arithmetic expression"
	"\nof the form 2+3*4/3-2."
	"\nNo number may have more than one digit."
	"\nDon’t use any spaces or parentheses.";
	do {
		cout << "\nEnter expresssion: ";
		cin >> string;                        //input from user
		express * eptr = new express(string);  //make expression
		eptr->parse();
		cout << "\nThe numerical value is: " << eptr->solve();
		delete eptr;
		cout << "\nDo another (Enter y or n)? ";
		cin >> ans;
	} while(ans == 'y');
	return 0;
}