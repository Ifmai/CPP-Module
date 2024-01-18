#include "AMateria.hpp"


AMateria::AMateria(){
	this->type = " ";
}

AMateria::AMateria(std::string const & type){
	this->type = type;
}

AMateria::AMateria(AMateria const& copy){
	this->type = copy.type;
}

AMateria::~AMateria(){
}

std::string const & AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& target){
	std::cout<< "inam gay" << std::endl;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	std::cout<< "inam gay" << std::endl;

}