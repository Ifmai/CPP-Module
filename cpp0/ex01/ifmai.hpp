#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "contact.hpp"


class PhoneBook: public Contact {
    private:
        Contact contact[8];
        int     count;

    public:
        void    printValues() const;
        void    add(std::string name, std::string surname, std::string phone, std::string nick_name, std::string darkest_secret);
        void    print_phone();
        void    print_display(int index);
        int     search();
        void    close_process();
};