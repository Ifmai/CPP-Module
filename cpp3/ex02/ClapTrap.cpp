#include "ClapTrap.hpp"


ClapTrap::ClapTrap(){
    this->name = "";
    this->hitPoints = 10;
    this->energyPoint = 10;
    this->attackDmg = 0;
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name){
    this->name = name;
    this->hitPoints = 10;
    this->energyPoint = 10;
    this->attackDmg = 0;
    std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy){
    *this = copy;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& object){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &object)
        return *this;
    this->attackDmg = object.attackDmg;
    this->hitPoints = object.hitPoints;
    this->energyPoint = object.energyPoint;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if(this->hitPoints > 0 && this->energyPoint > 0)
    {
        std::cout << "ClapTrap "<< this->name << " attacks " << target << ", causing "<< this->attackDmg << " points of damage!" << std::endl;
        this->energyPoint--;
    }
    else if (this->energyPoint == 0)
        std::cout << "Low Energy" << std::endl;
    else
        std::cout << "ClapTrap is die." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if(this->hitPoints > 0){
        std::cout << "ClapTrap " << this->name << " taking damage (" << amount << ") " << std::endl;
        this->hitPoints -= amount;
    }
    else
        std::cout << "ClapTrap is die." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if(this->hitPoints > 0 && this->energyPoint > 0){
        std::cout << "ClapTrap " << this->name << " repairing it self (+" << amount << ") "  << "(!This will cause an energy point!)" << std::endl;
        this->energyPoint--;
        this->hitPoints += amount;
        std::cout << "New Hit Points -> " << this->hitPoints << std::endl;
    }
    else if (this->energyPoint == 0)
        std::cout << "Low Energy" << std::endl;
    else
        std::cout << "ClapTrap is die." << std::endl;
}


int ClapTrap::get_hitPoints(){
    return this->hitPoints;
}

int ClapTrap::get_energyPoint(){
    return this->energyPoint;
}

int ClapTrap::get_attackDmg(){
    return this->attackDmg;
}
