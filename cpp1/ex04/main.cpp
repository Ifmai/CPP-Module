#include <iostream>
#include <fstream>

int main(int ac, char **arg) {
    if (ac != 4){
		std::cout << "./program <fileName> <search> <replace>" << std::endl;
		return (1);
    }
    std::string     s1 = arg[2];
    std::string     s2 = arg[3];
    std::size_t     found;
    std::ifstream    input;
    std::ofstream    output;
    std::string     buffer;
    std::string     inputFile = arg[1];

    input.open(inputFile);
    if (!input.is_open())
        std::cout << "File could not be opened!" << std::endl;
    output.open(inputFile.append(".replace"));
    if(!output.is_open())
        std::cout << "File could not be opened!" << std::endl;
    while (std::getline(input, buffer)) {
        while((found = buffer.find(s1)) != std::string::npos) {
            buffer.erase(found, s1.length());
            buffer.insert(found, s2);
            found += s1.length();
        }
        output << buffer << std::endl;
    }
    output.close();
    input.close();
}
