#include <iostream>
using namespace std;

void setString(string& str) {
    str = "Hello, World!";
}

int main() {
    string myString;
    setString(myString);
    cout << "String value: " << myString << endl;
    return 0;
}