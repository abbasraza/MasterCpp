//
//  main.cpp
//  NewAndDelete3
//
//  Created by abbas raza on 19/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/*
 - Usage of stpcpy(char * dst, const char * src);
 - strcpy() functions copy the string src to dst (including the terminating `\0' character.)

 const char * str = "Abbas"; // strlen = 5. total characters are 6 including null.
 char ar[] = "Abbas"; // strlen = 5. total characters 6. including null

 char ar[5] = {'A', 'b', 'b', 'a', 's'}; // strlen = 5. total characters = 5 no null.
 char ar[5] = "Abba"; // correct // strlen = 4; total characters are 5 including null.
 
 char * ar = new char[5]; // total space of 5 characters. lastone should be null.
 strcpy(ar, str);
 All characters from str till null char copied to ar. so 6 character will be copied from str to
 ar which has space allocated for only 5 characters. Bad. So ar should have 6 character space allocated.

 
 - strcpy is dangerous. src string longer than dest. All characters in src string till null copied to dest.
   will cause corruption.
 const char * str = "ABBASRAZA";
 char * ar = new char[5];
 strcpy(ar, str);
 
 so ar will be equal to "ABBASRAZA"
 
 - strcat(char *restrict s1, const char *restrict s2);
   The strcat() and strncat() functions append a copy of the null-terminated string s2 to the
   end of the null-terminated string s1, then add a terminating `\0'.
   The string s1 must have sufficient space to hold the result.
 
 - Object passed to function as parameter. The dtor will be called on parameter when function exits.
 
 -  If we want to use strcat instead of strcpy, we should initialize the newly
 allocated array tstr. Because if we don't initialize newly allocated memory,
 it will contain garbage and strcat will assume it as string and will append
 next to it. which will result in unexpected false results
 //		char * tstr = new char[ld + ls + 1]{""};
 //		strcat(tstr, str);
 //		strcat(tstr, c.str);
 
 - This program generates error "pointer being freed was not allocated" because
   all the objects will be destroyed when program exists. s3 was copied to s4.
   due to that s3 pointer was copied to s4. when s3 is destroyed, the memory its pointer
   points to is released. Then s4 will be destroyed. But s4 pointer is still pointer to memory
   which has been freed. so we are trying to free memory which is already free.
 
 - We need smart dtor. So that when s3 will be destroyed, the dtor will not free its pointer memory
   because its pointed by s4 pointer as well. So the memory should be freed only when no other is
   pointing to that memory. Sort of reference counting.
*/

#include <iostream>

class CString
{
private:
	char * str;
public:
	CString();
	CString(const char *);
	void print_string();
	void concat(const CString&);
	~CString();
};

CString::CString() : str(NULL)
{
	std::cout << "no arg ctor called" << std::endl;
}

CString::CString(const char * s)
{
	std::cout << "one argument ctor called" << s << std::endl;
	size_t len = strlen(s);
	str = new char[len + 1]; // we shouldn't alloc len size array. because strcpy will copy len + 1 characters to str.
	strcpy(str, s); 		// strcpy will also copy null char.
}

CString::~CString()
{
	if (str)
	{
		std::cout << "calling destructor for ptr " << static_cast<void*>(str) << std::endl;
		// clear memory on exit. expensive
		//std::memset(str, 0, strlen(str));
		delete[] str;
	}
	str = NULL;
}

void CString::print_string()
{
	void * ptr = str;
	std::cout << "Address:" << ptr << " str = " << (str ? str : "NULL") << std::endl;
}

/* use pass as reference, otherwise c's dtor will be called when function exits casuing pointer to be freed. */
void CString::concat(const CString& c)
{
	if (!str)
	{
		size_t len = strlen(c.str);
		str = new char[len + 1];
		strcpy(str, c.str);
		//CString(c.str); //wrong. this calls ctor and creates new obj.
	}
	else
	{
		size_t total_len = strlen(str) + strlen(c.str);

		char * tstr = new char[total_len + 1];
		strcpy(tstr, str);
		strcat(tstr, c.str);

		/* If we want to use strcat instead of strcpy, we should initialize the newly
		   allocated array tstr. Because if we don't initialize newly allocated memory,
		   it will contain garbage and strcat will assume it as string and will append
		   next to it. which will result in unexpected false results
		 //		char * tstr = new char[ld + ls + 1]{""};
		 //		strcat(tstr, str);
		 //		strcat(tstr, c.str);
	    */

		std::cout << "strlen = " << strlen(tstr) << std::endl;
		delete[] str;
		str = tstr;
	}
}

int main(int argc, const char * argv[])
{
	CString s1;

	CString s2("Hello");
	CString s3 = "How are you";

	/*
	 s3 copied to s4 member by member using copy ctor.
     s3.str pointer is copied to s4.str.
	 i.e
	 s4.str = s3.str;
	 so s4.str is pointing to same memory as s3.str.
	 no new memory allocated for s4.str.
    */
	CString s4 = s3; //default copy ctor called. pointer copied only. so s4.str = s3.str;

	std::cout << "s1 = "; s1.print_string();
	std::cout << "s2 = "; s2.print_string();
	std::cout << "s3 = "; s3.print_string();
	std::cout << "s4 = "; s4.print_string();

	s1.concat(s2);
	std::cout << "s1.concat(s2); s1 = "; s1.print_string();
	std::cout << "s1.concat(s2); s2 = "; s2.print_string();
	std::cout << "s1.concat(s2); s3 = "; s3.print_string();
	std::cout << "s1.concat(s2); s4 = "; s4.print_string();

	s1.concat(s3);
	std::cout << "s1.concat(s3); s1 = "; s1.print_string();
	std::cout << "s1.concat(s3); s2 = "; s2.print_string();
	std::cout << "s1.concat(s3); s3 = "; s3.print_string();
	std::cout << "s1.concat(s3); s4 = "; s4.print_string();

	return 0;
}

