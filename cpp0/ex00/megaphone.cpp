#include <cctype>
#include <iostream>

int main(int ac, char** arg)
{
    if(ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    for(int i = 1; i < ac ; i++)
    {
        for(int j = 0; arg[i][j] != '\0'; j++)
            arg[i][j] = std::toupper(arg[i][j]);
        if(i != ac - 1)
            std::cout << arg[i] << " ";
        else if(i == ac - 1)
            std::cout << arg[i] << std::endl;
    }
}
