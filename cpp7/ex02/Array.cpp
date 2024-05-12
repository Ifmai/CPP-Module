#include "Array.hpp"

template <typename T>
Array<T>::Array() : lenght(1){
    this->array = new T();
}

template <typename T>
Array<T>::Array(unsigned int n): lenght(n) {
    if (n > 0)
        this->array = new T[n]();
    else {
        std::cout << "Created Empty Array" << std::endl;
        this->array = new T();
        this->lenght = 1;
    }
}

template <typename T>
Array<T>::Array(const Array<T>& copy){
    if(this == &copy)
        return ;
    if(this->lenght != 0)
        delete[] this->array;
    this->lenght = copy.lenght;
    this->array = new T(this->lenght);
    for(int i = 0; i < lenght ; i++)
        this->array[i] = copy.array[i];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &copy) {
    if(this == &copy)
        return *this;
	if (this->lenght != 0)
		delete [] this->array;
	this-> lenght = copy.lenght;
	this->array = new T[lenght];
	for (unsigned int i = 0; i < this->lenght; i++)
		this->array[i] = copy.array[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
	if (index < 0 || index >= this->size())
		throw std::out_of_range("Out of interval of the array.");
	else
		return this->array[index];
}

template<typename T>
Array<T>::~Array() {
	if (lenght != 0)
		delete [] this->array;
}

template <typename T>
unsigned int Array<T>::size() const{
    return this->lenght;
}
