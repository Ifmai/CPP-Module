#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150){
	cout << "Bureaucrat Default Constructor Called" << endl;
}

Bureaucrat::Bureaucrat(string name_, int grade_): name(name_){
	cout << "Bureaucrat Constructor Called" << endl;
	try{
		this->setGrade(grade_);
	}
	catch(std::exception &e){
		cout << e.what() << endl;
		cout << "Default (150) value was assigned to the grade" << endl;
		this->grade = 150;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): name(copy.name), grade(copy.grade){
	cout << "Bureaucrat Copy Constructor Called" << endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy){
    cout << "Bureaucrat Copy assignment operator called" << endl;
    if(this == &copy)
        return *this;
	this->grade = copy.grade;
    return *this;
}

Bureaucrat::~Bureaucrat(){
    cout << "Bureaucrat Destructor called" << endl;
}

string Bureaucrat::getName()const{
	return name;
}

int Bureaucrat::getGrade()const{
	return grade;
}

const char * Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Grade is too high!"); 
}

const char * Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Grade is too low!"); 
}

void Bureaucrat::incrementGrade(){
	this->setGrade(grade - 1);
}

void Bureaucrat::decrementGrade(){
	this->setGrade(grade + 1);
}

void Bureaucrat::setGrade(int value){
	if(value <= 0)
		throw GradeTooHighException();
	else if (value > 150)
		throw GradeTooLowException();
	else
		this->grade = value;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& object){
	os << object.getName() << ", bureaucrat grade " << object.getGrade() << "." << endl;
	return os;
}

//ex01
void Bureaucrat::signForm(Form& form){
	if(form.getSignedForm() == false)
		form.beSigned(*this);
	else
		cout << "This form is already signed. Sorry " << this->getName() << "." << endl;
}

void Bureaucrat::executeForm(Form const & form){
	try{
		form.execute(*this);
		cout << this->getName() << " executed " << form.getName() << endl;
	}
	catch (const Form::GradeTooLowException &e){
		cout << e.what() << endl;
		cout << this->getName() << " is exec grade too low.." << endl;
	}
	catch (const Form::SignedFormExeption &e){
		cout << e.what() << endl;
		cout << this->getName() << " couldn't sign this form because it had already been signed." << endl;
	}
}