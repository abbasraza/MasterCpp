#include <iostream>
using namespace std;
/* C++ allows functions to be overloaded on the basis of the const-ness of parameters only if:
   the const parameter is a reference or a pointer
*/

void fun(char *a)
{
    cout << "non-const fun() " << a;
}

void fun(const char *a)
{
    cout << "const fun() " << a;
}

int main()
{
    const char *ptr = "GeeksforGeeks";
    fun(ptr);
    return 0;
}
