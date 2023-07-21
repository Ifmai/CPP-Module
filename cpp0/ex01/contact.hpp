#include <iostream>
#include <string>

class Contact {
    private :
        std::string name;
        std::string surname;
        std::string phone;
        std::string nick_name;
        std::string darkest_secret;

    public :
        void    set_name(std::string set_input){name = set_input;}
        void    set_surnamename(std::string set_input){surname = set_input;}
        void    set_phone(std::string set_input){phone = set_input;}
        void    set_nick_name(std::string set_input){nick_name = set_input;}
        void    set_darkest_secret(std::string set_input){darkest_secret = set_input;}
        std::string get_contact(std::string get_input);
};