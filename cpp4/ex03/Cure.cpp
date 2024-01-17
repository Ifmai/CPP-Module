#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::Cure(const Cure& copy){
	std::cout << "Cure Copy Constructor called" << std::endl;
	*this = copy;
}

Cure& Cure::operator=(const Cure& copy){
    std::cout << "Copy assignment operator called" << std::endl;
	this->type = copy.type;
}

AMateria* Cure::clone()const{
	Cure *ret = new Cure;
	return ret;
}