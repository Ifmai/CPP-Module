#include "Harl.hpp"

int main(int ac, char **arg) {
    if(ac == 1) {
        std::cout << "./program <MOD>" << std::endl;
        return (0);
    }
    Harl harl;
    harl.complain(arg[1]);
}