#include "RPN.hpp"

void getValues(int &value1, int &value2, std::stack<int> &list){
	value1 = list.top();
	list.pop();
	value2 = list.top();
	list.pop();
}

void selectProcessing(const int &value1, const int &value2, const char &process,std::stack<int> &list){
	switch (process)
	{
		case '+':
			list.push(value2 + value1);
			break;	
		case '-':
			list.push(value2 - value1);
			break;
		case '*':
			list.push(value2 * value1);
			break;
		case '/':
			list.push(value2 / value1);
			break;
		default:
			break;
	}
}

void runRPN(std::string input){
	if(input.find('(') != std::string::npos || input.find(')') != std::string::npos)
		std::cout << "Error." << std::endl;
	else{
		std::stack<int>	numberRPN;
		int value1;
		int value2;
		size_t i = 0;
		for(; i != input.length() ; i++){
			if(isdigit(input.at(i)))
				numberRPN.push(static_cast<int>(input.at(i)) - 48);
			else if(input.at(i) == '-' || input.at(i) == '+' || \
				input.at(i) == '*' || input.at(i) == '/'){
				if(numberRPN.size() < 2)
					break;
				getValues(value1, value2, numberRPN);
				selectProcessing(value1, value2, input.at(i), numberRPN);
			}
		}
		if(numberRPN.size() == 1 && i == input.length())
			std::cout << numberRPN.top() << std::endl;
		else
			std::cout << "Error." << std::endl;
	}
}