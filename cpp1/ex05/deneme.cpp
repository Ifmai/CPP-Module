#include <iostream>

int main()
{
    std::string level = "INFO";
    std::size_t found;
    std::string selectLevel = "DEBUG INFO WARNING ERROR";
    found = selectLevel.find(level);
    
    std::cout << found << std::endl;
}