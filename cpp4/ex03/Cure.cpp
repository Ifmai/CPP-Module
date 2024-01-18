#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::Cure(Cure const & copy){
	std::cout << "Cure Copy Constructor called" << std::endl;
	*this = copy;
}

Cure& Cure::operator=(Cure const & copy){
    std::cout << "Copy assignment operator called" << std::endl;
	this->type = copy.type;

	return *this;
}

AMateria* Cure::clone()const{
	AMateria *ret = new Cure;
	return ret;
}

void Cure::use(ICharacter& target){
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}