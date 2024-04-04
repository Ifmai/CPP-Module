#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():Form("PresidentialPardonForm", 25, 5), target("Default"){
	cout << "PresidentialPardonForm Default Constructor Called." << endl;
}

PresidentialPardonForm::PresidentialPardonForm(string target_):Form("PresidentialPardonForm", 25, 5), target(target_){
	cout << "PresidentialPardonForm Constructor Called." << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):Form("PresidentialPardonForm", 25, 5), target(copy.target){
	cout << "PresidentialPardonForm Copy Constructor Called" << endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy){
	cout << "Form Copy assignment operator called" << endl;
    if(this == &copy)
        return *this;
	this->target = copy.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    cout << "PresidentialPardonForm Destructor called" << endl;
}

string PresidentialPardonForm::getTarget()const{
	return target;
}

void PresidentialPardonForm::execute(const Bureaucrat& execute) const{
	if(this->getSignedForm() == true)
		throw Form::SignedFormExeption();
	if(this->getExecGrade() < execute.getGrade())
		throw Form::GradeTooLowException();
	cout << this->getTarget() << " Forgiven by Zaphod Beeblebrox." << endl;
}