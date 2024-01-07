#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(){
	this->name = "DiamondTrap";
	this->ClapTrap::name = "DiamondTrap_clap_name";
	this->FragTrap::hitPoints = 100;
	this->ScavTrap::energyPoint = 50;
	this->FragTrap::attackDmg = 30;
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name){
	this->name = name;
	this->ClapTrap::name = name + "_clap_name";
	this->FragTrap::hitPoints = 100;
	this->ScavTrap::energyPoint = 50;
	this->FragTrap::attackDmg = 30;
	std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy){
	*this = copy;
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy){
	    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;
    this->attackDmg = copy.attackDmg;
    this->hitPoints = copy.hitPoints;
    this->energyPoint = copy.energyPoint;
    return *this;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "Hi my name is: " << this->name << ", and my ClapTrap name is: " << ClapTrap::name << std::endl;
}
