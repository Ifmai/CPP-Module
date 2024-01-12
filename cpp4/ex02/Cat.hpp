#ifndef CAT_HPP
# define CAT_HPP

#include "Animals.hpp"

class Cat : public Animal {

    private:
        Brain *catBrain;

    public :
        Cat();
        Cat(const Cat& copy);
        Cat& operator=(const Cat& copy);
        ~Cat();

        void makeSound() const;
        std::string getType() const;
};

#endif