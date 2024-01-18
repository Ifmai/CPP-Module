#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(Ice const & copy){
	*this = copy;
}

Ice& Ice::operator=(Ice const & copy){
	this->type = copy.type;

	return *this;
}

Ice::~Ice(){}

AMateria* Ice::clone()const{
	AMateria *ret = new Ice;
	return ret;
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}