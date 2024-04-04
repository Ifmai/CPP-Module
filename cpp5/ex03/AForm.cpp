#include "AForm.hpp"

Form::Form() : name("Default"), signedForm(false), signedGrade(150), execGrade(150){
	cout << "Form Default Constructor Called" << endl;
}

Form::Form(string name_, int signedGrade_, const int execGrade_)
:name(name_), signedGrade(setSignedGrade(signedGrade_)), execGrade(setExecGrade(execGrade_))
{
	cout << "Form Constructor Called" << endl;
	this->signedForm = false;
}

Form::Form(const Form& copy)
:name(copy.name), signedForm(copy.signedForm), signedGrade(copy.signedGrade), execGrade(copy.execGrade)
{
	cout << "Form Copy Constructor Called" << endl;
}


Form& Form::operator=(const Form& copy){
	cout << "Form Copy assignment operator called" << endl;
    if(this == &copy)
        return *this;
	this->signedForm = copy.signedForm;
	this->signedGrade = copy.signedGrade;
    return *this;
}

Form::~Form(){
    cout << "Form Destructor called" << endl;
}

string Form::getName()const{
	return this->name;
}

bool Form::getSignedForm()const{
	return this->signedForm;
}

int Form::getSignedGrade()const{
	return this->signedGrade;
}

int Form::getExecGrade()const{
	return this->execGrade;
}

int Form::setExecGrade(int execGrade){
	try{
		if(execGrade < 1)
			throw GradeTooHighException();
		else if (execGrade > 150)
			throw GradeTooLowException();
		else
			return execGrade;
	}
	catch(std::exception &e){
		cout << e.what() << endl;
		cout << "Default (150) value was assigned to the exec grade" << endl;
		return 150;
	}
}

int Form::setSignedGrade(int signedGrade){
	try{
		if(signedGrade < 1)
			throw GradeTooHighException();
		else if (signedGrade > 150)
			throw GradeTooLowException();
		else
			return signedGrade;
	}
	catch(std::exception &e){
		cout << e.what() << endl;
		cout << "Default (150) value was assigned to the signed grade" << endl;
		return 150;
	}
}

const char * Form::GradeTooHighException::what() const throw(){
	return "The form exec/signed grade is too high.";
}

const char * Form::GradeTooLowException::what() const throw(){
	return "The form exec/signed grade is too low.";
}

const char * Form::SignedFormExeption::what() const throw(){
	return "This form is already signed.";
}

void Form::beSigned(Bureaucrat& bureaucrat){
	if(this->getSignedGrade() >= bureaucrat.getGrade()){
		cout << this->getName() << " signed " << bureaucrat.getName() << endl;
		this->signedForm = true;
	}
	else
		cout << this->getName() << " couldn’t signed " << name << " because " << this->getName() << " grade low." << endl;
}

std::ostream& operator<<(std::ostream& os, const Form& object){
	os	<< object.getName() << " Form Info.\n"
		<< "Is signed: " << (object.getSignedForm() ? "Yes" : "No") << ".\n"
		<< "Grade to sign: " << object.getSignedGrade() << ".\n"
		<< "Grade to execute: " << object.getExecGrade() << "." << endl;
	return os;
}