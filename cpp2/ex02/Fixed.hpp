#include <iostream>
#include <cmath>

class Fixed {
    private :
        int fixed_int;
        const static int cons_bit = 8;

    public :
        // Constructor & Destructor Define Start.
        Fixed();
        ~Fixed();
        Fixed(const int fixed);
        Fixed(const float fixed);
        Fixed(const Fixed& fixed);
        // Constructor & Destructor Define End.
    

        //Compare Operators Start.
        Fixed& operator=(const Fixed& fixed);
        bool operator<(const Fixed& fixed);
        bool operator<=(const Fixed& fixed);
        bool operator>(const Fixed& fixed);
        bool operator>=(const Fixed& fixed);
        bool operator==(const Fixed& fixed);
        bool operator!=(const Fixed& fixed);
        //Compare Operators End.


        //Arithmetic Operators Start.
        Fixed operator+(const Fixed& fixed);
        Fixed operator-(const Fixed& fixed);
        Fixed operator*(const Fixed& fixed);
        Fixed operator/(const Fixed& fixed);

        Fixed operator++(int);
        Fixed& operator++();

        Fixed operator--(int);
        Fixed& operator--();
        //Arithmetic Operators End.


        // Min and Max Function Start.
        static Fixed& Min(Fixed& fixed1, Fixed& Fixed2);
        static const Fixed& Min(const Fixed& fixed1, const Fixed& Fixed2);
        static Fixed& Max(Fixed& fixed1, Fixed& fixed2);
        static const Fixed& Max(const Fixed& fixed1, const Fixed& Fixed2);
        // Min and Max Function End.


        // Get and Set Function Start.
        int     getRawBits() const;
        void    setRawBits(int const raw);
        // Get and Set Function End.


        // Convert Function Start.
        float   toFloat() const;
        int     toInt() const;
        // Convert Function End.
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);