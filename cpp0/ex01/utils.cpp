#include "ifmai.hpp"

using std::strcat;

char* PhoneBook::setString(int index, std::string getInput){
    if (this->contact[index].get_contact(getInput).size() <= 10)
        return strndup(this->contact[index].get_contact(getInput).c_str(), this->contact[index].get_contact(getInput).size());
    else
        return strcat(strndup(this->contact[index].get_contact(getInput).c_str(), 9), ".");
}

void PhoneBook::print_phone(){
    int searchIndex;
    int i;
    std::cout << "----------------------PHONEBOOK-------------------------" << std::endl;
    for(i = 0; i < 4 ; i++){
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << "|" << std::setw(10) << setString(i, "name");
        std::cout << "|" << std::setw(10) << setString(i, "surname");
        std::cout << "|" << std::setw(10) << setString(i, "phone");
        std::cout << "|" << std::setw(10) << setString(i, "nick_name");
        std::cout << "|" << std::setw(10) << setString(i, "darkest_secret");
        std::cout << "|" << std::endl;
    }
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "Search Index :";
    std::cin >> searchIndex;
    if(searchIndex <= 8 && searchIndex >= 0){
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << "|" << std::setw(10) << setString(searchIndex, "name");
        std::cout << "|" << std::setw(10) << setString(searchIndex, "surname");
        std::cout << "|" << std::setw(10) << setString(searchIndex, "phone");
        std::cout << "|" << std::setw(10) << setString(searchIndex, "nick_name");
        std::cout << "|" << std::setw(10) << setString(searchIndex, "darkest_secret");
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

std::string Contact::get_contact(std::string get_input){
    if(get_input == "name")
        return name;
    else if(get_input == "surname")
        return surname;
    else if(get_input == "phone")
        return phone;
    else if(get_input == "nick_name")
        return nick_name;
    else if(get_input == "darkest_secret")
        return darkest_secret;
    else
        return NULL;
}