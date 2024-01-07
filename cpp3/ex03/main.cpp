#include "ScavTrap.hpp"

int main(){
    ScavTrap ab("alp");
    ScavTrap ba("berna");

    ba.attack("alp");
    ab.takeDamage(ba.get_attackDmg());
    ab.beRepaired(ba.get_attackDmg());
}