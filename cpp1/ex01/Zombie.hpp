#include <iostream>

class Zombie {
    private :
        std::string name;
        int count;
    
    public :
        Zombie();
        ~Zombie();
        void announce();
        void setName(std::string setName);
        std::string getName();
};

Zombie*    zombieHorde(int n, std::string name);
