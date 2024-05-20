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

/* void startPmergeMeList(std::list<int> &listShort){
	
	std::cout << "Time to process a range of " << listShort.size() << " elements with std:list<int> : " << progressTime << " us." << std::endl;
	//mergeShortDeque(dequeShort, dequeShort.begin(), dequeShort.end());
	std::cout << "Time to process a range of " << dequeShort.size() << " elements with std:deque<int> : " << progressTime << " us." << std::endl;
	orospuSıraları(listShort.begin(), listShort.end());
	orospuSıraları2(dequeShort.begin(), dequeShort.end());
} */


	//mergeShortTempalte(listShort, listShort.begin(), listShort.end());
	//mergeShortTempalte(dequeShort, dequeShort.begin(), dequeShort.end());
	//printContainer(listShort, dequeShort);