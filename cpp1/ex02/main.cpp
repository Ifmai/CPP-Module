#include <iostream>

int main() {
    std::string s = "HI THIS IS BRAIN";
    std::string *stringPTR = &s;
    std::string &stringREF = s;

    std::cout << "String değişkeninin bellek adresi : "<< &s << std::endl;
    std::cout << "stringPTR tarafından tutulan bellek adresi :" << &stringPTR << std::endl;
    std::cout << "stringRef tarafından tutulan bellek adresi :" << &stringREF << std::endl;

    std::cout << "String değişkeninin bellek adresi : "<< s << std::endl;
    std::cout << "stringPTR tarafından tutulan bellek adresi :" << *stringPTR << std::endl;
    std::cout << "stringRef tarafından tutulan bellek adresi :" << stringREF << std::endl;
}
