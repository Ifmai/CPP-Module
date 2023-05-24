#include <iostream>
#include <string>


class PhoneBook {
    private:
        std::string name;
        std::string surname;
        std::string phone;
        std::string nick_name;
        std::string darkest_secret;

    public:
        PhoneBook() {
            name = "";
            surname = "";
            phone = "";
            nick_name = "";
            darkest_secret = "";
            std::cout << "Create PhoneBook Class" << std::endl;
        }

        PhoneBook(const PhoneBook& other) {
            name = other.name;
            surname = other.surname;
            phone = other.phone;
            nick_name = other.nick_name;
            darkest_secret = other.darkest_secret;
        }

        PhoneBook& operator=(const PhoneBook& other) {
            if (this != &other) {
                name = other.name;
                surname = other.surname;
                phone = other.phone;
                nick_name = other.nick_name;
                darkest_secret = other.darkest_secret;
            }
            return *this;
        }

        void printValues() const {
            std::cout <<
        }
};