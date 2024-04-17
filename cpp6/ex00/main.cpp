#include "ScalarConverter.hpp"

int main(int argc, std::string* input){
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [input]" << std::endl;
		return (0);
	}
	ScalarConverter::convert(std::string(input[1]));
}