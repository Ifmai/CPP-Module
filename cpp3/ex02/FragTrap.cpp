#include "FragTrap.hpp"


FragTrap::FragTrap(){
	this->name = "";
    this->hitPoints = 100;
    this->energyPoint = 100;
    this->attackDmg = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name){
	this->name = name;
    this->hitPoints = 100;
    this->energyPoint = 100;
    this->attackDmg = 30;
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy){
	*this = copy;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy){
	    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;
    this->attackDmg = copy.attackDmg;
    this->hitPoints = copy.hitPoints;
    this->energyPoint = copy.energyPoint;
    return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target){
    if(this->hitPoints > 0 && this->energyPoint > 0)
    {
        std::cout << "FragTrap "<< this->name << " attacks " << target << ", causing "<< this->attackDmg << " points of damage!" << std::endl;
        this->energyPoint--;
    }
    else if (this->energyPoint == 0)
        std::cout << "Low Energy" << std::endl;
    else
        std::cout << "FragTrap is die." << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "👋🏻 Hey guys how about a high five? 👋🏻" << std::endl;
}