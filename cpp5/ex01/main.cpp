#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	Thor("Thor", 10);
	Form		f("EB115", 10, 10);

	Thor.signForm(f);
	std::cout << f << std::endl; 
	Bureaucrat	Alp("Alp", 10);
	std::cout << f << std::endl; 
	Alp.signForm(f);
	return 0;
}

