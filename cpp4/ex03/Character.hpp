#ifndef CHARACTER_HPP
# define CHARACTER_HP

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
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif