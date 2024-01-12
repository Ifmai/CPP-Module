#ifndef DOG_HPP
# define DOG_HPP

#include "Animals.hpp"

class Dog : public Animal {
    private:
        Brain* dogBrain;
    public :
        Dog();
        Dog(const Dog& copy);
        Dog& operator=(const Dog& copy);
        ~Dog();
        
        void makeSound() const;
        std::string getType() const;
};

#endif