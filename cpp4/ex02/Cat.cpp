#include "Cat.hpp"

Cat::Cat(){
    this->type = "Cat";
    std::cout << "Cat Default Constructor called" << std::endl;
    this->catBrain = new Brain();
}

Cat::Cat(const Cat& copy){
    *this = copy;
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;

    Brain *deepCopy = new Brain();
    this->type = copy.type;
    for(int i = 0; i < 100; i++)
        deepCopy->setIdeas(i, copy.catBrain->getIdeas(i));
    this->catBrain = deepCopy;
    return *this;
}

Cat::~Cat() {
    delete this->catBrain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << " 🐾 uWu Miav Miav uWu 🐾 " << std::endl;
}

std::string Cat::getType() const{
    return this->type;
}
