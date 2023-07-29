#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
    private :
        std::string name;
        Weapon *weapon;
    
    public :
        HumanA(std::string name, Weapon *weapon);
        void attack();
        void setWeapon(Weapon *inputWeapon);
        void setName(std::string inputName);
        std::string getName();
};

#endif