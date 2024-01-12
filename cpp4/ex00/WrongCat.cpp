#include "WrongCat.hpp"

WrongCat::WrongCat(){
    this->type = "WrongCat";
    std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type){
    this->type = type;
    std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy){
    *this = copy;
    std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;
    this->type = copy.type;
    
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << " 🐾 uWu Miav Miav uWu 🐾 " << std::endl;
}


std::string WrongCat::getType() const{
    return this->type;
}