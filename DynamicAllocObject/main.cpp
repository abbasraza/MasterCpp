//
//  main.cpp
//  DynamicAllocObject
//
//  Created by abbas raza on 24/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Dynamically allocating objects.
 - Destroying dynamically allocated objects.
 - new doesn't zero memory. whenever allocating memory using new, null/zero it.
 - If object of foo is allocated from heap using new, ctor should null any member pointers.
 - Any object allocated on stack (created inside function body, in arguments) will be automatically
   destroyed (by calling ctor) when it goes out of scope (i.e function exits)
 - Any object dynamically allocated (on heap) doesn't get automatically destroyed when going out of scope
   i.e when function exits. It should be freed/destroyed manually. by calling delete which calls dtor.
 - foo * f1 = new foo; This means member ptr will be null(if set if ctor) or contain garbage. i.e ptr
   doesn't point to any valid allocated memory yet.
 - foo * f2 = new foo(5,10);
   delete f2; // this means delete will not free memory pointed to by member ptr. should be freed in dtor.
*/

#include <iostream>

class foo
{
private:
	int students[20];
	int * ptr;
	int var;
public:
	foo():students(), ptr(NULL), var(0)
	{
		std::cout << "in no arg ctor\n";
	}
	foo (int p, int v):students{}, ptr(new int(p)), var(v)
	{
		std::cout << "in 2 arg ctor\n";
	}
	void display_foo()
	{
		std::cout << "ptr = " << ptr << std::endl;
		if (ptr) {
			std::cout << "*ptr = " << *ptr << std::endl;
		}
		std::cout << "var = " << var << std::endl;
		for (int i = 0; i < 20; ++i)
		{
			std::cout << "students[" << i << "] = " << students[i] << std::endl;
		}
	}
	~foo()
	{
		std::cout << "dtor called" << std::endl;
		if (ptr) {
			std::cout << "freeing memory pointed to by = " << ptr << std::endl;
			delete ptr;
		}
	}
	int * return_ptr()
	{
		return ptr;
	}
};

void bar()
{
	foo f1;
	f1.display_foo();
	
	/*
	 This will call no arg ctor.
	 All members will be allocated on heap.
	 ptr variable will be allocated on heap.
	 ptr should be nulled in ctor.
    */
	foo * f2 = new foo;
	f2->display_foo();
	
	foo * f3 = new foo(10, 5); // this will call 2 arg ctor;
	f3->display_foo();

	// on function exit, f1 goes out of scope. so dtor for this will
    // be automatically called.
	
	// on function exit, any dynamically allocated object will not be destroyed automatically.
	// we will have to free it manually if we don't need it.
	/* This will calle dtor. we should free any memory we have allocated. */
	delete f2;
	delete f3;
}

int main(int argc, const char * argv[])
{
	bar();
	return 0;
}
