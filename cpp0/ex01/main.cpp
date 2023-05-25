#include "ifmai.hpp"

int main() {
    std::string value;
    std::cout << "Bir metin girin: ";
    std::getline(std::cin, value);
    std::cout << "Girdiğiniz metin: " << value << std::endl;
    PhoneBook();
    return 0;
}
