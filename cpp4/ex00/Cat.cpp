#include "Cat.hpp"

Cat::Cat(){
    this->type = "Cat";
    std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(std::string type){
    this->type = type;
    std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat& copy){
    *this = copy;
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;
    this->type = copy.type;
    
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << " 🐾 uWu Miav Miav uWu 🐾 " << std::endl;
}

std::string Cat::getType() const{
    return this->type;
}