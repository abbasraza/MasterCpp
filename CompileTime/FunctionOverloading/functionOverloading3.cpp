#include<iostream>
using namespace std;
//function name same
//Parameters should have a different sequence of parameters.

void add(int a, double b)
{ 
	cout<<"sum = "<<(a+b);
} 

void add(double a, int b)
{
	cout<<endl<<"sum = "<<(a+b);
} 

// Driver code
int main()
{
	add(10,2.5);
	add(5.5,6);

    // this will give error:
    // more than one instance of overloaded function "add" matches the argument list:
    //add(5,6);

	return 0;
}
