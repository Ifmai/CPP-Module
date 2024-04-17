#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

enum typeConvert{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

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

		std::string getType(const std::string input);

	public:
		static void convert(const std::string input);
		static void resultPrintChar(std::string input, bool anyInfinity);
		static void resultPrintInt(std::string input, bool anyInfinity);
		static void resultPrintFloat(std::string input, bool anyInfinity);
		static void resultPrintDobule(std::string input, bool anyInfinity);
};

#endif