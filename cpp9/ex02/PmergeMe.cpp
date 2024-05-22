#include "PmergeMe.hpp"

const char* InvalidArgument::what() const throw(){
	return "Invalid argument: not a number";
}

void printList(std::list<int>::iterator left, std::list<int>::iterator right){
	while(left != right){
		std::cout << *left << " ";
		left++;
	}
	std::cout << std::endl;
}

void printDeque(std::deque<int>::iterator left, std::deque<int>::iterator right){
	while(left != right){
		std::cout << *left << " ";
		left++;
	}
	std::cout << std::endl;
}

bool anyLetter(std::string input){
	for (size_t i = 0; i < input.size(); ++i) {
		if(i == 0 && (input[i] == '+' || input[i] == '-'))
			i++;
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

bool listInValueList(std::list<int> &list, char **argList){
	int value = 0;
	try{
		for(size_t i = 0; argList[i] != 0; i++ ){
			if(!anyLetter(argList[i]))
				throw InvalidArgument();
			value = std::stoi(argList[i]);
			list.push_back(value);
		}
	}catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
        return false;
    }
	return true;
}

bool listInValueDeque(std::deque<int> &list, char **argList){
	int value = 0;
	try{
		for(size_t i = 0; argList[i] != 0; i++ ){
			if(!anyLetter(argList[i]))
				throw InvalidArgument();
			value = std::stoi(argList[i]);
			list.push_back(value);
		}
	}catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
        return false;
    }
	return true;
}