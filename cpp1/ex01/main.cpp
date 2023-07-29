#include "Zombie.hpp"


int main() {
    Zombie *zombieptr = zombieHorde(5, "alp");

    delete []zombieptr;
}
