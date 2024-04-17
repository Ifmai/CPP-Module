#include <iostream>


int main(){
    std::string a = "1233fff";


    int deneme = std::stoi(a);
/* 
    float dd = std::stof(a);
    int deneme = static_cast<int>(dd);
    std::cout << "float : " << dd << std::endl; */
    std::cout << "int : " << deneme << std::endl;
}