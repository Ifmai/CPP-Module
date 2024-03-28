#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150){
	cout << "Default Constructor Called" << endl;
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
	cout << "Copy Constructor Called" << endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy){
    cout << "Copy assignment operator called" << endl;
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