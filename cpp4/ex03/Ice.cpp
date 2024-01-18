#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice Default Constructor called" << std::endl;
}

Ice::Ice(Ice const & copy){
	std::cout << "Ice Copy Constructor called" << std::endl;
	*this = copy;
}

Ice& Ice::operator=(Ice const & copy){
    std::cout << "Copy assignment operator called" << std::endl;
	this->type = copy.type;

	return *this;
}

AMateria* Ice::clone()const{
	AMateria *ret = new Ice;
	return ret;
}

void Ice::use(ICharacter& target){
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}