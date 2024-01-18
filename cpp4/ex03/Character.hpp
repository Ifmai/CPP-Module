#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter{
	private:
		std::string name;
		AMateria* inventory[4];
		int ammount;
		Character();

	public:
		Character(std::string const name);
		Character(const Character& copy);
		Character& operator=(const Character& copy);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* material);
		void unequip(int index);
		void use(int index, ICharacter& target);
		AMateria* getEquip(int index);
};

#endif