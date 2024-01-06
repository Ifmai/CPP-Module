#include "ScavTrap.hpp"

int main(){
    ClapTrap a("Alp");
    ClapTrap b("Ali");

    a.attack("Ali");
    b.takeDamage(a.get_attackDmg());
    b.beRepaired(3);
    
    b.attack("Alp");
    a.takeDamage(b.get_attackDmg());
    a.beRepaired(20);

    ScavTrap ab("alp");
}