#include <iostream>
#include <string>

class MyClass {
   private :
        int legal;
        std::string papuc;
        int illegal;

    public : 
        MyClass();
        MyClass(int x, std::string d, int z);
        void setdata(int x, std::string d, int z);
        void getdata();
};