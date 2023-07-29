#include "Zombie.hpp"

Zombie::Zombie() {
    static int i = 0;
    this->count = i;
    std::cout << "Create Zombie " << i << std::endl;
    i++;
}

Zombie::~Zombie() {
    std::cout << "Delete " << this->count << " Zombie " << "Name : " << getName() << std::endl;
}

void Zombie::announce(void) {
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName() {
    return name;
}

void Zombie::setName(std::string setName) {
    name = setName;
}