#include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog";
    std::cout << "Dog Default Constructor called" << std::endl;
    this->dogBrain = new Brain();
}

Dog::Dog(const Dog& copy){
    *this = copy;
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;

    Brain* deepCopy = new Brain();
    this->type = copy.type;
    for(int i = 0; i < 100; i++)
        deepCopy->setIdeas(i, copy.dogBrain->getIdeas(i));
    this->dogBrain = deepCopy;
    return *this;
}

Dog::~Dog() {
    delete this->dogBrain;
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const{
    std::cout << " 🐺 40 Hav Hav 58 🦴 " << std::endl;
}

std::string Dog::getType() const{
    return this->type;
}