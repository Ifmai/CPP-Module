#include "BitcoinExchange.hpp"


void BitcoinExchange::readDB(std::string findString){
	std::ifstream readFile;
	if(findString == ",")
		readFile.open(this->btcFile);
	else
		readFile.open(this->inputFile);
	if(!readFile.is_open())
		std::cerr << "Not Open File" << std::endl;
	
	std::string line;
	int 		pos;
	double 		price;
	std::string	tempPrice;
	std::string date;
	// First Line Skip.
	// date,exchange_rate
	std::getline(readFile, line); 
	while(std::getline(readFile, line)){
		pos = line.find(findString);
		if(findString == "|" && pos == -1){
			this->inputDB.push_back(std::pair<std::string, double>(line + " bad", -1001)); // bad input;
			continue;
		}
		else if(pos == -1)
			continue;
		date = line.substr(0, pos);
		tempPrice = line.substr(pos + 1);
		price = strtod(tempPrice.c_str(), NULL);
		if(findString == ",")
			this->btcDB.insert(std::pair<std::string, double>(date, price));
		else{
			date = date.substr(0,date.size() - 1); // Last " " remove.
			this->inputDB.push_back(std::pair<std::string, double>(date, price));
		}
	}
	if(findString == "|" && this->inputDB.size() == 0)
		this->emptyFile = 1;
	readFile.close();
}