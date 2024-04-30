#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


static int i = 0;

Base* generate() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // srand kullanırken statik dönüşüm yapılmalıdır.
    int random_number = rand() % 3;
    std::cout << "random number : " << random_number << std::endl;
    switch (random_number) {
        case 0:
            return (new A);
        case 1:
            return (new B());
        case 2:
            return (new C());
        default:
            std::cout << "Invalid Random Number" << std::endl;
            return nullptr; // nullptr kullanılmalıdır.
    }
}


void identify(Base *p){
    if (i++ == 0 && dynamic_cast<A *>(p)) {
        std::cout << "Pointer is pointing to an object of class A" << std::endl;
        return ;
    }
    else if (i++ == 1 && dynamic_cast<B *>(p)) {
        std::cout << "Pointer is pointing to an object of class B" << std::endl;
        return ;
    }
    else if (i == 2 && dynamic_cast<C *>(p)) {
        std::cout << "Pointer is pointing to an object of class C" << std::endl;
        return ;
    } else {
        std::cout << "Pointer is pointing to an unknown object" << std::endl;
        return ;
    }
    i = 0;
}

void identify(Base &p){
    std::string listArrat[] = {"A", "B", "C"};

    while(i < 3){
        try{
            identify(&p);
            break;
        }
        catch(std::exception &e){
            (void)e;
            i++;
            identify(&p);
        }
        i++;
    }
	return;
}