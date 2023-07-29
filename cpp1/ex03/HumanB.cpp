#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    setName(name);
}

void HumanB::attack() {
    std::cout << getName() << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setName(std::string inputName) {
    this->name = inputName;
}

void HumanB::setWeapon(Weapon *inputWeapon) {
    this->weapon = inputWeapon;
}

std::string HumanB::getName() {
    return this->name;
}