#include "Character.hpp"

Character::Character(){
	this->name = "";
	this->ammount = 0;
	std::cout << "Character Default Constructor Called" << std::endl;
}

Character::Character(std::string const name){
	this->name = name;
	this->ammount = 0;
	std::cout << "Character Constructor Called" << std::endl;
}

Character::Character(const Character& copy){
	this->ammount = 0;
	*this = copy;
	std::cout << "Character Copy Constructor Called" << std::endl;
}

Character::~Character(){
	for(int i = 0; i < this->ammount; i++)
		delete this->inventory[i];
}

Character& Character::operator=(const Character& copy){
	for(int i = 0; i < this->ammount; i++)
		delete this->inventory[i];
	
	this->name = copy.name;
	this->ammount = copy.ammount;
	for(int i = 0; i < this->ammount; i++)
		this->inventory[i] = copy.inventory[i]->clone();
	
	return *this;
}

std::string const & Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* material){
	if(this->ammount <= 4)
		return;
	for (int i = 0 ; i < this->ammount ; i++){
		if(this->inventory[i] == material)
			return;
	}
	this->inventory[this->ammount] = material;
	this->ammount++;
}

void Character::unequip(int index){
	if (index >= 0 && index < this->ammount)
	{
		for (int i = index + 1; i < this->ammount; i++)
			this->inventory[i - 1] = this->inventory[i];
		this->ammount--;
	}
}

void Character::use(int index, ICharacter& target){
	if(index >= 0 && index < this->ammount)
		this->inventory[index]->use(target);
}

AMateria* Character::getEquip(int index){
	return ((index >= 0 && index < this->ammount) ? this->inventory[index] : NULL);
}
