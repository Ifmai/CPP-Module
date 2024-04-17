#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& copy){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy){}
ScalarConverter::~ScalarConverter(){}


std::string ScalarConverter::getType(const std::string input){
	if(input.length() == 0)
		return "empty";
	else if((input.compare("nan") == 0) || (input.compare("+inf") == 0) || (input.compare("-inf") == 0)
		|| (input.compare("-inff") == 0) || (input.compare("+inff") == 0) || (input.compare("nanf") == 0))
		return "infinity";
	else if(input.length() == 1 && !std::isdigit(input[0]))
		return "char";
	else if (input.find(".") != std::string::npos){
		if (input[input.length() - 1] == 'f'){
			try{
				this->fValue = std::stof(input);
				return "float";
			}
			catch (const std::invalid_argument& e) {
				return "Argument Error";
    		}
		}
		else {
			try{
				double Value = std::stod(input);
				return "double";
			}
			catch (const std::invalid_argument& e) {
				return "Argument Error";
    		}
		}
	}
	else {
		try{
			int iValue = std::stoi(input);
			return "int";
		}
		catch (const std::invalid_argument& e) {
			return "Argument Error";
    	}
	}
}

void ScalarConverter::resultPrintChar(std::string input, bool anyInfinity){
	char out = static_cast<char>(input[0]);
	if(!isprint(out) && anyInfinity == true)
		std::cout << "char : imposible" << std::endl;
	else if(!isprint(out))
		std::cout << "char : non displayable" << std::endl;
	else
		std::cout << "char : '" << out << "'" << std::endl;
}

void ScalarConverter::resultPrintInt(std::string input, bool anyInfinity){
	if(anyInfinity == true)
		std::cout << "int : imposible" << std::endl;
}

void ScalarConverter::resultPrintFloat(std::string input, bool anyInfinity){
	if(anyInfinity == true){
		if (!input.compare("nan") || !input.compare("nanf"))
			std::cout << "nanf";
		else if (!input.compare("+inf") || !input.compare("+inff"))
			std::cout << "+inff";
		else
			std::cout << "-inff";
	}
	else {
		try{
			float out = std::stof(input);
			std::cout << "float : " << out << "f" << std::endl; 
		}
		catch (const std::out_of_range& e){
			std::cout << "float : out of range " << std::endl;
		}
	}
}

void ScalarConverter::resultPrintDobule(std::string input, bool anyInfinity){
	if(anyInfinity == true){
		if (!input.compare("nan") || !input.compare("nanf"))
			std::cout << "nanf";
		else if (!input.compare("+inf") || !input.compare("+inff"))
			std::cout << "+inff";
		else
			std::cout << "-inff";
	}
	else {
		try{
			double out = std::stod(input);
			std::cout << "double : " << out << std::endl; 
		}
		catch (const std::out_of_range& e){
			std::cout << "double : out of range " << std::endl;
		}
	}
}

void ScalarConverter::convert(const std::string input){
	ScalarConverter a;
	bool anyInfinity = false;
	std::string convertType = a.getType(input);
	
	if(convertType == "infinity")
		anyInfinity = true;
	if(convertType == "empty")
		std::cout << "Error: ./convert [Empty]" << std::endl;
	else if (convertType == "Argument Error")
		std::cout << "Error: ./convert [Invalid İnput]" << std::endl;
	//yazdırılabilir mi diye hepsi private veriye aktarılcak.
	//sonrasında print methodu yazılcak getlerle birlikte.
	// beynim yandı amk.
}