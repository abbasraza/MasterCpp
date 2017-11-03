//
//  main.cpp
//  MutableKeyword
//
//  Created by abbas raza on 2/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of mutable keyword.
 - Only const function can be called on const obeject.
 - Const function can't modify any object data.
 - No data of const object can be modified.
 - In some cases where we will need to modify some parameters of const object, we make those parameters mutable
   so that they can be changed in future.
*/


#include <iostream>

class TelstraPlan
{
private:
	mutable std::string owner;
	int charges_per_month;
	int data_allowance;
	int period;
public:
	TelstraPlan():owner(""), charges_per_month(150), data_allowance(50), period(2)
	{
		
	}
	TelstraPlan(std::string o, int c, int d, int p):owner(o), charges_per_month(c), data_allowance(d), period(p)
	{
		
	}
	void show_plan() const
	{
		std::cout << "Owner: " << owner << std::endl << "Charges Per Month $: " << charges_per_month << std::endl << "Data Allowed GB: " << data_allowance << std::endl << "Plan period (YEARS): " << period << std::endl;
	}
	void change_ownership(std::string new_owner) const
	{
		owner = new_owner;
	}
	
};
int main(int argc, const char * argv[])
{
	const TelstraPlan p1("Abbas Raza", 150, 50, 2);
	p1.show_plan();
	
	p1.change_ownership("Fasiha Sadaf");
	p1.show_plan();
	
    return 0;
}
