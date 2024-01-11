#include "Fixed.hpp"

// Constructor & Destructor Define Start.
Fixed::Fixed() {
    this->fixed_int = 0;
    std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int fixed) {
    this->fixed_int = fixed * pow(2, this->cons_bit);
    std::cout << "İnt constructor called." << std::endl;
}

Fixed::Fixed(const float fixed) {
    this->fixed_int = roundf(fixed * pow(2, this->cons_bit));
    std::cout << "Float constructor called." << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed){
    this->fixed_int = fixed.fixed_int;
    std::cout << "Copy constructor called" << std::endl;
}
// Constructor & Destructor Define End.


//Compare Operators Overloading Start.
Fixed& Fixed:: operator=(const Fixed& fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &fixed) // Kendi nesnesine atama kontrolü
        return *this;
    this->fixed_int = fixed.fixed_int;
    return *this;
}

bool Fixed:: operator<(const Fixed& fixed)
{
    if(this->fixed_int < fixed.fixed_int)
        return (true);
    return (false);
}


bool Fixed:: operator<=(const Fixed& fixed)
{
    if(this->fixed_int <= fixed.fixed_int)
        return (true);
    return (false);
}


bool Fixed:: operator>(const Fixed& fixed)
{
    if(this->fixed_int < fixed.fixed_int)
        return (true);
    return (false);
}


bool Fixed:: operator>=(const Fixed& fixed)
{
    if(this->fixed_int < fixed.fixed_int)
        return (true);
    return (false);
}

bool Fixed:: operator==(const Fixed& fixed)
{
    if(this->fixed_int == fixed.fixed_int)
        return (true);
    return (false);
}

bool Fixed:: operator!=(const Fixed& fixed)
{
    if(this->fixed_int != fixed.fixed_int)
        return (true);
    return (false);
}
//Compare Operators Overloading End.


//Arithmetic Operators Overloading Start.
Fixed Fixed::operator+(const Fixed& fixed) {
    Fixed resultObj;
    resultObj.fixed_int = this->fixed_int + fixed.fixed_int;
    return resultObj;
}

Fixed Fixed::operator-(const Fixed& fixed) {
    Fixed resultObj;
    resultObj.fixed_int = this->fixed_int - fixed.fixed_int;
    return resultObj;
}

Fixed Fixed::operator*(const Fixed& fixed) {
    Fixed resultObj;
    resultObj.fixed_int = this->fixed_int * fixed.fixed_int;
    return resultObj;
}

Fixed Fixed::operator/(const Fixed& fixed) {
    Fixed resultObj;
    resultObj.fixed_int = this->fixed_int / fixed.fixed_int;
    return resultObj;
}


Fixed Fixed::operator++(int) {
    Fixed resultOBJ = *this;
    this->fixed_int++;
    return resultOBJ;
}

Fixed& Fixed::operator++() {
    this->fixed_int++;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed resultOBJ = *this;
    this->fixed_int--;
    return resultOBJ;
}

Fixed& Fixed::operator--() {
    this->fixed_int--;
    return (*this);
}
//Arithmetic Operators Overloading End.


// Min and Max Function Start.
Fixed& Fixed::Min(Fixed& fixed1, Fixed& fixed2) {
    if(fixed1 < fixed2)
        return fixed1;
    return fixed2;
}

const Fixed& Fixed::Min(const Fixed& fixed1, const Fixed& fixed2) {
    if(fixed1.fixed_int < fixed2.fixed_int)
        return fixed1;
    return fixed2;
}

Fixed& Fixed::Max(Fixed& fixed1, Fixed& fixed2) {
    if(fixed1 > fixed2)
        return fixed1;
    return fixed2;
}

const Fixed& Fixed::Max(const Fixed& fixed1, const Fixed& fixed2) {
    if(fixed1.fixed_int > fixed2.fixed_int)
        return fixed1;
    return fixed2;
}
// Min and Max Function End.


// Get and Set Function Start.
int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_int;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_int = raw;
}
// Get and Set Function Start.


// Convert Function Start.
int Fixed::toInt() const {
    return ((this->fixed_int / pow(2, this->cons_bit)));
}

float Fixed::toFloat() const {
    return ((float)this->fixed_int / pow(2, this->cons_bit));
}
// Convert Function End.


std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}