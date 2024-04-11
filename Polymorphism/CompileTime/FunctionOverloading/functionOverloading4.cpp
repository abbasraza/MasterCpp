#include <iostream>
using namespace std;

/* C++ allows functions to be overloaded on the basis of the const-ness of parameters only if:
   the const parameter is a reference or a pointer
*/
void fun(const int i)
{
    cout << "fun(const int) called ";
}

//this will give a compile time error
// redefinition of ‘void fun(int)’

void fun(int i)
{
    cout << "fun(int ) called ";
}

int main()
{
    const int i = 10;
    fun(i);
    return 0;
}
