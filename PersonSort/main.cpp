// persort.cpp
// sorts person objects using array of pointers

#include <iostream>
#include <string>

using namespace std;

class person
{
protected:
	string name;
public:
	void setName()
	{
		cout << "Enter name: ";
		cin >> name;
	}
	void printName()
	{
		cout << endl << name;
	}
	string getName()
	{
		return name;
	}
};

int main()
{
	//void bsort(person**, int);
	person * persPtr[100];
	int n = 0;
	char choice;
	do
	{
		persPtr[n] = new person;
		persPtr[n]->setName();
		n++;
		cout << "Enter another (y/n)? "; //enter another
		cin >> choice;              //   person?
	}
	while (choice=='y');
	
	cout << "\nUnsorted list:";
	
	for (int j=0; j<n; j++)
	{
		persPtr[j]->printName();
	}
	bsort(persPtr, n);
	cout << "\nSorted list:";
	for(j=0; j<n; j++)
	{
		persPtr[j]->printName();
	}
	cout << endl;
	return 0;
}  //end main()