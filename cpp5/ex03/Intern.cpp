#include "Intern.hpp"

Intern::Intern(){
	cout << "Intern Default Constructor Called" << endl;

	formList["Robotomy Request"] = &createRobotomyRequestForm;
    formList["Presidential Pardon"] = &createPresidentialPardonForm;
    formList["Shrubbery Creation"] = &createShrubberyCreationForm;
}

Intern::Intern(const Intern& copy){
	(void)copy;
	cout << "Intern Copy Constructor Called" << endl;
}

Intern& Intern::operator=(const Intern& copy){
	(void)copy;
	cout << "Intern Copy Assignment Operator Called" << endl;
	return *this;
}

Intern::~Intern(){
	cout << "Intern Destructor Called" << endl;
}

Form* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

Form* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Form* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

Form* Intern::makeForm(const string formName, const string target) {
    std::map<std::string, FormCreationFunction>::iterator it = formList.find(formName);
    if (it != formList.end()) {
		cout << "Intern creates " << formName << endl;
        return (it->second)(target);
    }
    else {
        cout << "Invalid form name. The form could not be created." << endl;
        return NULL;
    }
}