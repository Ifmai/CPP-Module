#include "deneme.hpp"

MyClass::MyClass() {
    std::cout << "Hello World!" << std::endl;
}

void MyClass::setdata(int x, std::string d, int z){
    legal = x;
    papuc = d;
    illegal = z;
}

void MyClass::getdata(){
  std::cout << legal << " " << papuc << " " << illegal << std::endl;
}

MyClass::MyClass(int x, std::string d, int z) {
    setdata(x,d,z);
}

int main() {
  MyClass myObj; // Create an object of MyClass
  MyClass obj2(15,"selam",20);
  obj2.getdata();
  return 0;
}