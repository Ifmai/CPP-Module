#include "ifmai.hpp"


int main() {
    PhoneBook myphone;
    std::string input;
    std::string name;std::string surname;std::string phone;std::string nick_name;std::string darkest_secret;
    while(1)
    {
        std::cout << "ADD | SEARCH | EXIT" << " -> ";
        std::cin >> input;
        if(input == "ADD"){

            std::cout << "Name = "; std::cin >> name;
            std::cout << "Surname = "; std::cin >> surname;
            std::cout << "Phone = "; std::cin >> phone;
            std::cout << "Nick Name = "; std::cin >> nick_name;
            std::cout << "Darkest Secret = "; std::cin >> darkest_secret;
            myphone.add(name,surname,phone,nick_name,darkest_secret);
        }
        else if (input == "SEARCH")
            myphone.print_phone();
        else if (input == "EXIT")
            exit(0);
    }
    return 0;
}
