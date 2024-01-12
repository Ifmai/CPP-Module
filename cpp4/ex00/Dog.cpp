#include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog";
    std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(std::string type){
    this->type = type;
    std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog& copy){
    *this = copy;
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;
    this->type = copy.type;
    
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const{
    std::cout << " 🐺 40 Hav Hav 58 🦴 " << std::endl;
}

std::string Dog::getType() const{
    return this->type;
}