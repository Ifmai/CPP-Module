#ifndef ANIMALS_HPP
# define ANIMALS_HPP

#include <iostream>

class Animal {
    
    protected:
        std::string type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& copy);
        Animal& operator=(const Animal& copy);
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;
};

#endif