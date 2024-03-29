#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const& copy);
		virtual ~AMateria();
		
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0; // Abstract Class
		virtual void use(ICharacter& target);
};

#endif