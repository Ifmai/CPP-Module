#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    setType(type);
}

const std::string& Weapon::getType() {
    return this->type;
}

void Weapon::setType(std::string typeSet) {
    this->type = typeSet;
} 