#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice Default Constructor called" << std::endl;
}

Ice::Ice(const Ice& copy){
	std::cout << "Ice Copy Constructor called" << std::endl;
	*this = copy;
}

Ice& Ice::operator=(const Ice& copy){
    std::cout << "Copy assignment operator called" << std::endl;
	this->type = copy.type;
}

AMateria* Ice::clone()const{
	Ice *ret = new Ice;
	return ret;
}