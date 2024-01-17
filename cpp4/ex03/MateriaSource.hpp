#ifndef MATERIALSOURCE_HPP
# define MATERIALSOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
	private:
		AMateria* learn[4];
		int ammount;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator=(const MateriaSource& copy);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif