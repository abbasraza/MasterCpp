//
//  main.cpp
//  PersonSort
//
//  Created by abbas raza on 25/11/17.
//  Copyright © 2017 Self. All rights reserved.
//
//

/* Purpose of this program:
 - Array of dynamically allocated objects
 - Array of pointers to dynamically allocated objects
 - Sorting of persons based on their names
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

- Array of pointers to objects vs array of objects. Which one better for sorting algo.
  obviously the former is preferred because no copying will be involved.
 
 - Reference to temporary should be constant.
   reference to temporary variable: (should be ref to const)
   int & ref = 15; //wrong
 
   it should be ref to const int.
   const int & ref = 15;
 
  reference to temporary pointer: (should be ref to const pointer)
  int * ptr = new int[10];
  int * & ref = ptr + 1; //wrong
 
  it should be ref to const pointer
  int * const & ref = ptr + 1;
 
 - Usage of pointer to pointer (double pointer)
 
*/

#include <iostream>

class person
{
protected:
	std::string name;
public:
	person(const char * n) : name(n)
	{
	}
	void setName()
	{
		std::cout << "Enter name: ";
		std::cin >> name;
	}
	void printName()
	{
		std::cout << std::endl << name;
	}
	std::string getName()
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


void order2(person * & p1, person * & p2)
{
	person * t = p1;
	p1 = p2;
	p2 = t;
}

void bubble_sort2(person * persons_array[], int elements)
{
	for (int i = 0; i < elements - 1; ++i)
	{
		for (int j = i + 1; j < elements; ++j)
		{
			if (persons_array[i]->getName() > persons_array[j]->getName()) // note * is inside brackets
			{
				order2(persons_array[i], persons_array[j]);
			}
		}
	}
}

void bubble_sort3(person * persons_ptr, int elements)
{
	for (int i = 0; i < elements - 1; ++i)
	{
		for (int j = i + 1; j < elements; ++j)
		{
			if (persons_ptr[i].getName() > persons_ptr[j].getName()) // note * is inside brackets
			{
				/* reference to temporary pointer doesn't work this way */
				//order2((persons_ptr + i), (persons_ptr + j));
				
				/* reference to temporary pointer should be reference to constant pointer
				   but we can't use const pointer here */
				
				/* so we create non temp pointers */
				person * p1 = persons_ptr + i;
				person * p2 = persons_ptr + j;
				order2(p1, p2);
			}
		}
	}
}


int main()
{
	/*
     #########################################################
							 1st way
     #########################################################
    */
	person * persPtr[4];
	const char * names[] = {"Washington", "Adams", "Jefferson", "Madison"};
	int n = 0;
	//char choice;
	//do
	for (; n < 4; ++n)
	{
		persPtr[n] = new person(names[n]);
		//persPtr[n]->setName();
		//++n;
		//std::cout << "Enter another (y/n)? "; //enter another
		//std::cin >> choice;              //   person?
	}
	//while (choice=='y');
	
	std::cout << "\nUnsorted list:";
	
	for (int j=0; j<n; j++)
	{
		persPtr[j]->printName();
	}

	bubble_sort2(persPtr, n);

	std::cout << "\n\nSorted list:";
	for(int j=0; j<n; j++)
	{
		persPtr[j]->printName();
	}
	std::cout << std::endl;
	
    for (n = 0; n < 4; ++n)
	{
		delete persPtr[n];
	}

	
	/*
	 #########################################################
							 2nd way
	 #########################################################
    */

	person * pers_ptr = new person[4]{"Washington", "Adams", "Jefferson", "Madison"};
	
	std::cout << "\nUnsorted list:";
	for (int j = 0; j < n; ++j)
	{
		/* All are same */
		//pers_ptr[j].printName();
		//(*(pers_ptr + j)).printName();
		(pers_ptr + j)->printName();
	}
	
	bubble_sort3(pers_ptr, n);
	
	std::cout << "\n\nSorted list:";
	for(int j=0; j<n; j++)
	{
		pers_ptr[j].printName();
	}
	std::cout << std::endl;
	
	
	delete[] pers_ptr;
	

	return 0;
}
