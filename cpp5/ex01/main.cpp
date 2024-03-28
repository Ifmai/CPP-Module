#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	Thor("Thor", 156);
	Form		f("EB115", 0, 156);

	f.beSigned(Thor);
	std::cout << f << std::endl; 
	Bureaucrat	Alp("Alp", 10);
	f.beSigned(Alp);
	std::cout << f << std::endl; 

	return 0;
}

