#include "ifmai.hpp"

using std::strcat;
using std::strncpy;

void PhoneBook::print_phone(){
    int searchIndex;
    std::cout << "----------------------PHONEBOOK-------------------------" << std::endl;
    for(int i = 0; i < 4 ; i++){
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << "|" << std::setw(10) << ((this->contact[i].get_name().size() < 10) ? (this->contact[i].get_name()) : (strcat(strndup(this->contact[i].get_name().c_str(), 9), ".")));
        std::cout << "|" << std::setw(10) << ((this->contact[i].get_surname().size() < 10) ? (this->contact[i].get_surname()) : (strcat(strndup(this->contact[i].get_surname().c_str(), 9), ".")));
        std::cout << "|" << std::setw(10) << ((this->contact[i].get_phone().size() < 10) ? (this->contact[i].get_phone()) : (strcat(strndup(this->contact[i].get_phone().c_str(), 9), ".")));
        std::cout << "|" << std::setw(10) << ((this->contact[i].get_nick_name().size() < 10) ? (this->contact[i].get_nick_name()) : (strcat(strndup(this->contact[i].get_nick_name().c_str(), 9), ".")));
        std::cout << "|" << std::setw(10) << ((this->contact[i].get_darkest_secret().size() < 10) ? (this->contact[i].get_darkest_secret()) : (strcat(strndup(this->contact[i].get_darkest_secret().c_str(), 9), ".")));
        std::cout << "|" << std::endl;
    }
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Search Index :";
    std::cin >> searchIndex;
    if(searchIndex <= 8 && searchIndex >= 1){
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << "|" << std::setw(10) << ((this->contact[searchIndex].get_name().size() < 10) ? (this->contact[searchIndex].get_name()) : (strcat(strndup(this->contact[searchIndex].get_name().c_str(), 9), ".")));
        std::cout << "|" << std::setw(10) << ((this->contact[searchIndex].get_surname().size() < 10) ? (this->contact[searchIndex].get_surname()) : (strcat(strndup(this->contact[searchIndex].get_surname().c_str(), 9), ".")));
        std::cout << "|" << std::setw(10) << ((this->contact[searchIndex].get_phone().size() < 10) ? (this->contact[searchIndex].get_phone()) : (strcat(strndup(this->contact[searchIndex].get_phone().c_str(), 9), ".")));
        std::cout << "|" << std::setw(10) << ((this->contact[searchIndex].get_nick_name().size() < 10) ? (this->contact[searchIndex].get_nick_name()) : (strcat(strndup(this->contact[searchIndex].get_nick_name().c_str(), 9), ".")));
        std::cout << "|" << std::setw(10) << ((this->contact[searchIndex].get_darkest_secret().size() < 10) ? (this->contact[searchIndex].get_darkest_secret()) : (strcat(strndup(this->contact[searchIndex].get_darkest_secret().c_str(), 9), ".")));
        std::cout << "|" << std::endl;
    }
    else
        std::cout << "The index count must be between one and eight" << std::endl;
}

void PhoneBook::add(std::string name, std::string surname, std::string phone, std::string nick_name, std::string darkest_secret)
{
    static int mod = 0;
    this->contact[mod].set_name(name);
    this->contact[mod].set_surnamename(surname);
    this->contact[mod].set_phone(phone);    
    this->contact[mod].set_nick_name(nick_name);
    this->contact[mod].set_darkest_secret(darkest_secret);
    mod++;
    if(mod % 7 == 0)
        mod = 0;
}