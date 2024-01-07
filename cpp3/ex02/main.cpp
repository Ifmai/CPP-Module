#include "FragTrap.hpp"

int main(){
    FragTrap ab("alp");
    FragTrap ba("berna");

    ba.attack("alp");
    ab.takeDamage(ba.get_attackDmg());
    ab.beRepaired(ba.get_attackDmg());
}