#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <algorithm>

class Span{
    private:
        
        int             arraySize;

    public:
        Span();
        Span(int _arraySize);
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        ~Span();

        void    addNumber(int value);
        int     shortestSpan(int value);
        int     longestSpan(int value);
        int     addNumbers(int value);

        
};

#endif