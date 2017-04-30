// persort.cpp
// sorts person objects using array of pointers
/*
 Sample input:
 Enter name: Washington
 Enter another (y/n)? y
 Enter name: Adams
 Enter another (y/n)? y
 Enter name: Jefferson
 Enter another (y/n)? y
 Enter name: Madison
 Enter another (y/n)? n
 
 Unsorted list:
 Washington
 Adams
 Jefferson
 Madison
 
 Sorted list:
 Adams
 Jefferson
 Madison
 Washington
*/

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

void order(person ** p1, person ** p2)
{
	person * t = *p1;
	*p1 = *p2;
	*p2 = t;
}

void bubble_sort(person ** pers_ptr, int elements)
{
	for (int i = 0; i < elements - 1; ++i)
	{
		for (int j = i + 1; j < elements; ++j)
		{
			person ** p1 = pers_ptr + i;
			person ** p2 = pers_ptr + j;
			if ((*p1)->getName() > (*p2)->getName()) // note * is inside brackets
			{
				order(p1, p2);
			}
		}
	}
}

int main()
{
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

	bubble_sort(persPtr, n);

	cout << "\n\nSorted list:";
	for(int j=0; j<n; j++)
	{
		persPtr[j]->printName();
	}
	cout << endl;
	return 0;
}  //end main()