#include "ScavTrap.hpp"


ScavTrap::ScavTrap(){
    this->name = "";
    this->hitPoints = 100;
    this->energyPoint = 50;
    this->attackDmg = 20;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name){
    this->name = name;
    this->hitPoints = 100;
    this->energyPoint = 50;
    this->attackDmg = 20;
    std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy){
    *this = copy;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& object){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &object)
        return *this;
    this->attackDmg = object.attackDmg;
    this->hitPoints = object.hitPoints;
    this->energyPoint = object.energyPoint;
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if(this->hitPoints > 0 && this->energyPoint > 0)
    {
        std::cout << "ScavTrap "<< this->name << " attacks " << target << ", causing "<< this->attackDmg << " points of damage!" << std::endl;
        this->energyPoint--;
    }
    else if (this->energyPoint == 0)
        std::cout << "Low Energy" << std::endl;
    else
        std::cout << "ScavTrap is die." << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}