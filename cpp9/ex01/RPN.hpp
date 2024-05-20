#include <iostream>
#include <stack>

void runRPN(std::string input);
void getValues(int &value1, int &value2, std::stack<int> &list);
void selectProcessing(const int &value1, const int &value2, const char &process,std::stack<int> &list);