#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	this->ammount = 0;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	this->ammount = 0;
	*this = copy;
}


MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
	for (int i = 0; i < this->ammount; i++)
		delete this->learn[i];

	this->ammount = copy.ammount;
	for (int i = 0; i < this->ammount; i++)
		learn[i] = copy.learn[i]->clone();
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < this->ammount; i++)
		delete this->learn[i];
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (this->ammount >= 4)
		return;
	for (int i = 0; i < this->ammount; i++)
		if (this->learn[i] == materia)
			return;

	this->learn[this->ammount] = materia;
	this->ammount++;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < this->ammount; i++)
		if (this->learn[i]->getType() == type)
			return (this->learn[i]->clone());
	return (NULL);
}
