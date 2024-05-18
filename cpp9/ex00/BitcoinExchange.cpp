#include "BitcoinExchange.hpp"

/* BitcoinExchange::BitcoinExchange(){
	std::cout << "Default Constructor Called" << std::endl;
} */

BitcoinExchange::BitcoinExchange(std::string _inputDB, std::string _btcdb)
	: btcFile(_btcdb), inputFile(_inputDB){
		std::cout << "Constructor Called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
	:btcFile(copy.btcFile), inputFile(copy.inputFile), btcDB(copy.btcDB), inputDB(copy.inputDB){
		std::cout << "Copy Constructor Called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy){
	if(this == &copy)
		return *this;
	this->btcDB.clear();
	this->inputDB.clear();
	this->btcDB = copy.btcDB;
	this->inputDB = copy.inputDB;
	this->btcFile = copy.btcFile;
	this->inputFile = copy.inputFile;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){
	std::cout << "Destructor Called" << std::endl;
}
