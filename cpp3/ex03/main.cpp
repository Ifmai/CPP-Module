#include "DiamondTrap.hpp"

int main(){
    DiamondTrap ab("alp");
    std::cout << std::endl;
    DiamondTrap ba("berna");
    std::cout << std::endl;
    ba.attack("alp");
    std::cout << std::endl;
    ab.takeDamage(ba.get_attackDmg());
    std::cout << std::endl;
    ab.beRepaired(ba.get_attackDmg());
    std::cout << std::endl;

    ab.whoAmI();
    ba.whoAmI();
    std::cout << std::endl;

}