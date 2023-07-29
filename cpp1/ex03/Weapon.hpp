#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon {
    private :
        std::string type;
    
    public :
        Weapon(std::string type);
        void setType(std::string typeSet);
        const std::string& getType();
};
#endif