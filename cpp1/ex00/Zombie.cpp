#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "Creat Zombie" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Delete Zombie: " << getName() << std::endl;
}

void Zombie::announce(void) {
    std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string setName) {
    name = setName;
}

std::string Zombie::getName() {
    return name;
}