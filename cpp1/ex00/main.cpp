#include "Zombie.hpp"


int main()
{
    Zombie zombie;
    Zombie *zombieptr = zombie.newZombie("Berna");
    

    zombie.randomChump("Alp");
    zombieptr->announce();

    delete(zombieptr);
}