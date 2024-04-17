#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class ScalarConverter {
	private:
		char	cValue;
		int 	iValue;
		float	fValue;
		double	dValue;
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
		~ScalarConverter();

		//Convert
		std::string getType(const std::string input);
		void resultCasting(std::string input, std::string typeConvert, bool anyInfinity);

		//Print	
		void resultPrintChar(bool anyInfinity);
		void resultPrintInt(bool anyInfinity);
		void resultPrintFloatDouble(std::string input, std::string type, bool anyInfinity);
				
	public:
		static void convert(const std::string input);
};

#endif