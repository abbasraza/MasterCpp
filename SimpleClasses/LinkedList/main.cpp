//
//  main.cpp
//  LinkList
//
//  Created by abbas raza on 30/04/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Link list implementation.
*/

#include <iostream>

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
		while (head)
		{
			link * t = head;
			head = head->next;
			delete t;
		}
	}
	void addItem(int d);
	void deleteItem(int d);
	void display();
};

void linklist::addItem(int d)
{
	std::cout << "Adding item " << d << std::endl;

	link * newlink = new link;
	newlink->data = d;
	newlink->next = head;
	head = newlink;
}

void linklist::deleteItem(int d)
{
	std::cout << "Deleting item " << d << std::endl;

	if (head && (head->data == d))
	{
		link * t = head;
		head = head->next;
		delete t;
	}
	else
	{
		link * t = head;
		while(t && t->next)
		{
			if (t->next->data == d)
			{
				link * matched = t->next;
				t->next = matched->next;
				delete matched;
			}
			else
			{
				t = t->next;
			}
		}
	}
}

void linklist::display()
{
	if (!head)
	{
		std::cout << "list is empty";
		return;
	}
	
	link * t = head;
	while (t)
	{
		std::cout << t->data << " ";
		t = t->next;
	}
	std::cout << std::endl;
}

int main()
{
	linklist li;
	li.addItem(25);
	li.addItem(36);
	li.addItem(49);
	li.addItem(64);

	std::cout << "Original list:" << std::endl;
	li.display();

	li.deleteItem(36);
//	li.deleteItem(36);
//	li.deleteItem(49);
//	li.deleteItem(64);
//	li.deleteItem(100);
//
//	li.addItem(15);

	std::cout << "Modified list" << std::endl;
	li.display();
	
	/* The dtor will be automatically called when function exits */
	std::cout << "destroying list" << std::endl;
	li.~linklist();
	li.display();

	return 0;
}
