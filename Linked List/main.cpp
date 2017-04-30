//
//  main.cpp
//  LinkList
//
//  Created by abbas raza on 30/04/2017.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>
using namespace std;

struct link
{
	int data;
	link * next;
};

class linklist
{
private:
	link * head;
public:
	linklist()
	{
		head = NULL;
	}
	~linklist()
	{
		link * curr = head;
		while (curr)
		{
			link * t = curr;
			head = curr = curr->next;
			delete t;
		}
	}
	void additem(int d);
	void deleteitem(int d);
	void display();
};

void linklist::additem(int d)
{
	cout << "Adding item " << d << endl;

	link * newlink = new link;
	newlink->data = d;
	newlink->next = head;
	head = newlink;
}

void linklist::deleteitem(int d)
{
	cout << "Deleting item " << d << endl;

	link * curr = head;
	link * prev = head;
	while (curr)
	{
		if (curr->data == d)
		{
			if (curr == head)
			{
				head = curr->next;
				curr->next = NULL;
				delete curr;
			}
			else
			{
				link * deleted = curr;

				curr = curr->next;
				prev->next = curr;

				//deleted->next = NULL;
				delete deleted;
				continue;
			}
		}
		prev = curr;
		curr = curr->next;
	}
}

void linklist::display()
{
	if (!head)
	{
		cout << "list is empty";
	}
	
	link * current = head;
	while (current)
	{
		cout << current->data << " ";	//print data
		current = current->next;        //move to next link
	}
	cout << endl;
}

int main()
{
	linklist li; // allocated on stack
	li.additem(25);
	li.additem(36);
	li.additem(49);
	li.additem(64);
	
	cout << "Original list" << endl;
	li.display();      //display entire list

	li.deleteitem(25);
	li.deleteitem(36);
	li.deleteitem(49);
	li.deleteitem(64);
	li.deleteitem(100);

	li.additem(15);

	//li.deleteitem(49);

	cout << "Modified list" << endl;

	li.display();      //display entire list

	cout << "destroying list" << endl;
	li.~linklist(); // no need to call the destructor explicitly. 
	li.display();      //display entire list
	return 0;
}