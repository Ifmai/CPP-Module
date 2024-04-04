#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat	Thor("Thor", 1);
	Intern intern;
	Form *formPTR;


	formPTR =  intern.makeForm("Robotomy Request", "EFE");
	if(formPTR)
		Thor.executeForm(*formPTR);
	else {
		cout << "Not Created Form." << endl;
		exit(1);
	}

	delete formPTR;
	return 0;
}

