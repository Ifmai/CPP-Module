#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name) {
    Zombie *zombi_new = new Zombie();
    zombi_new->setName(name);
    return zombi_new;
}