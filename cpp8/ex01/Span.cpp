#include "Span.hpp"


Span::Span(): arraySize(0){
    std::cout << " Default Constructor Called" << std::endl;
}

Span::Span(int _arraySize): arraySize(_arraySize){
    std::cout << "Constructor Called" << std::endl;
}

Span::Span(const Span& copy){
    std::cout << "Copy Constructor Called" << std::endl;
    this->arraySize = copy.arraySize;
    std::set<int>::iterator it;
    
}