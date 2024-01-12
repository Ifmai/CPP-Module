#include "Animals.hpp"

Animal::Animal(){
    this->type = "Animal";
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(std::string type){
    this->type = type;
    std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal& copy){
    *this = copy;
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;
    this->type = copy.type;

    return *this;
}

Animal::~Animal() {
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const{
    std::cout << "Animals Sound 🔊" << std::endl;
}

std::string Animal::getType() const{
    return this->type;
}