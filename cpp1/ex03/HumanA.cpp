#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon *weapon) {
    setName(name);
    setWeapon(weapon);
}

void HumanA::attack() {
    std::cout << getName() << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanA::setWeapon(Weapon *inputWeapon) {
    this->weapon = inputWeapon;
}

void HumanA::setName(std::string inputName) {
    this->name = inputName;
}

std::string HumanA::getName() {
    return this->name;
}