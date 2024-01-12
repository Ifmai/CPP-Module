#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    this->type = "WrongAnimal";
    std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type){
    this->type = type;
    std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy){
    *this = copy;
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;
    this->type = copy.type;

    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal Sound 🔊" << std::endl;
}

std::string WrongAnimal::getType() const{
    return this->type;
}