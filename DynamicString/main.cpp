//
//  main.cpp
//  DynamicString
//
//  Created by abbas raza on 25/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - std::string has sort of internal char pointer. its ctor allocates variable itself on stack but string memory on heap
   dtor frees that automatically. We don't need to worry about that. we just need to delete what we have allocated
   using new.
 
 class foo1
 {
 private:
	 std::string s;
 }
 
 class foo2
 {
 private:
	 std::string * s;
 }

 1) foo1 f; //when goes out of scope, f will be destroyed, so the string inside it. we don't need to worry.
 2) foo1 * f = new foo1; // when goes out of scope, we should delete f. no need to worry about string inside.
 3) foo2 f; // when goes out of scope, we should delete any member dynamically allocated.
 4) foo2 f = new foo2; // when goes out of scope, we should delete f; we should free any member dynamically allocated.
 5) std::string s = "Hello"; // when going out of scope, we don't need to worry
 6) std::string * s = new std::string("Hello"); // when going out of scope, we should delete s.

 */

#include <iostream>

int main(int argc, const char * argv[]) {
	std::string * s1 = new std::string("Hello");
	std::string s12 = "Hello";
	std::string * s2 = &s12;

	std::cout << s1 << std::endl;
	std::cout << *s1 << std::endl;

	return 0;
}
