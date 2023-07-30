#include "Harl.hpp"

void Harl::debug() {
    std::cout << "[ DEBUG ]" << std::endl;
	std ::cout <<"  I love having extra bacon for my 7XL-double-cheese"
				 "-triple-pickle-specialketchup burger. I really do!"
				 << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "  I cannot believe adding extra bacon costs more money. You didn’t put"
			 "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			 << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]" << std::endl;
	std::cout<<"    I think I deserve to have some extra bacon for free."<<std::endl 
            << "    I’ve been coming for years whereas you started working here since last month."
            <<std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]" << std::endl;
	std::cout << "    This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    complains comp[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string selectLevel[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for(int i = 0; i < 4; i++)
    {
        if(level == selectLevel[i]) {
            (this->*comp[i])();
            if(i != 3)
                for(int j = i + 1; j < 4; j++)
                    (this->*comp[j])();
            break;
        }
        if(i == 3)
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}