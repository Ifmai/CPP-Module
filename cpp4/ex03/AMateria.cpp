#include "AMateria.hpp"


AMateria::AMateria(){
	this->type = " ";
	std::cout << "Abstract Materia Default Constructor Called" << std::endl;
}

AMateria::AMateria(std::string const & type){
	this->type = type;
	std::cout << "Abstract Materia Constructor Called" << std::endl;
}


AMateria::AMateria(AMateria const& copy){
	this->type = copy.type;
	std::cout << "Abstract Materia Copy Constructor Called" << std::endl;
}

AMateria::~AMateria(){
	std::cout << "Abstract Materia Destroyed" << std::endl;
}

std::string const & AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& targer){
	std::cout << "* shoots an ice bolt at " << targer.getName() << " *" << std::endl;

}