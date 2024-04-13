
#include <iostream>

class Employee
{
private:
	std::string name;
	int id;
public:
	Employee(std::string n = "", int i = 0) : name(n), id(i)
	{
	
	}
	void show_employee()
	{
		std::cout << "Name: " << name << '\n' << "ID: " << id << std::endl;
	}
    virtual void show_position() = 0;
};

class Scientist : private Employee
{
private:
	int publications;
public:
	Scientist(std::string n = "", int i = 0, int p = 0) : Employee(n, i), publications(p)
	{
		
	}
	void show_scientist()
	{
		//Employee::show_employee(); // don't need scope resolution here.
		show_employee();
		std::cout << "Publications: " << publications << std::endl;
 	}
    void show_position()
    {
        std::cout << "Scientist" << std::endl;
    }
};

class Labor : public Employee
{
public:
	Labor(std::string n = "", int i = 0) : Employee(n, i) // we can initialize the base class constructor
	{
		
	}
	void show_labor()
	{
		//Employee::show_employee();
		show_employee(); // don't need scope resolution here.
	}
    void show_position()
    {
        std::cout << "Labor" << std::endl;
    }
};

int main(int argc, const char * argv[])
{
	//Employee e; // Error: cannot declare variable ‘e’ to be of abstract type ‘Employee’
	Scientist e1("Abbas", 17);
	Labor e2("Shahg", 100);

	e1.show_scientist();
	e2.show_labor();

	return 0;
}
