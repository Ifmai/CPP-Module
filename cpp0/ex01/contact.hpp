#include <iostream>
#include <string>

class Contact {
    private :
        std::string name = "";
        std::string surname = "";
        std::string phone = "";
        std::string nick_name = "";
        std::string darkest_secret = "";

    public :
        void    get_data(std::string const get_input);
        void    set_data(std::string set_input);
};