#include <iostream>

class Fixed {
    private :
        int fixed_point;
        const static int fixed_int = 8;

    public :
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed();

        int getRawBits() const;
        void setRawBits(int const raw);
};