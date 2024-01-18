#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(Cure const & copy){
	*this = copy;
}

Cure::~Cure(){}

Cure& Cure::operator=(Cure const & copy){
	this->type = copy.type;

	return *this;
}

AMateria* Cure::clone()const{
	AMateria *ret = new Cure;
	return ret;
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}