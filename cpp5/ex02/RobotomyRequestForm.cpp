#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():Form("RobotomyRequestForm", 72, 45), target("Default"){
	cout << "RobotomyRequestForm Default Constructor Called." << endl;
}

RobotomyRequestForm::RobotomyRequestForm(string target_):Form("RobotomyRequestForm", 72, 45), target(target_){
	cout << "RobotomyRequestForm Constructor Called." << endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy):Form("RobotomyRequestForm", 72, 45), target(copy.target){
	cout << "RobotomyRequestForm Copy Constructor Called" << endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy){
	cout << "Form Copy assignment operator called" << endl;
    if(this == &copy)
        return *this;
	this->target = copy.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    cout << "RobotomyRequestForm Destructor called" << endl;
}

string RobotomyRequestForm::getTarget()const{
	return target;
}

void RobotomyRequestForm::execute(const Bureaucrat& execute) const{
	if(this->getSignedForm() == true)
		throw Form::SignedFormExeption();
	if(this->getExecGrade() < execute.getGrade())
		throw Form::GradeTooLowException();

		std::srand(std::time(nullptr));
		int random_number = rand() % 101;
		cout << "random number : " << random_number << endl;
		if(random_number % 2 == 0)
			cout << this->getTarget() << " has been robotomized successfully" << endl;
		else
			cout << this->getTarget() << " the robotomy failed." << endl;
}