#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria {
	public:
		Cure();
		Cure(Cure const & copy);
		Cure& operator=(Cure const & copy);
		~Cure();

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif