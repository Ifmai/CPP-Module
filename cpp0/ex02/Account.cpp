#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

    int	Account::_nbAccounts = 0;
	int	Account::_totalAmount = 0;
	int	Account::_totalNbDeposits = 0;
	int	Account::_totalNbWithdrawals = 0;
    static int acc_index = 0;

Account::Account(int initial_deposit){
    this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    Account::_nbAccounts += 1;
    this->_accountIndex = acc_index;
    acc_index++;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";" \
    << "amount:" << this->_amount << ";" \
    << "created" << std::endl;
}

Account::~Account(void){
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";" \
    << "amount:" << this->_amount << ";" \
    << "closed" << std::endl;
}

int Account::getNbAccounts(void){
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void){
    return Account::_totalAmount;
}

int Account::getNbDeposits(void){
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void){
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void){
    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::getNbAccounts() << ";" \
    << "total:" << Account::getTotalAmount() << ";" \
    << "deposits:" << Account::getNbDeposits() << ";"\
    << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit){
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";" \
    << "p_amount:" << this->_amount << ";" \
    << "deposit:" << deposit << ";";
    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalNbDeposits += 1;
    std::cout << "amount:" << this->_amount << ";" \
    << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
    Account::_displayTimestamp();
    if(this->_amount - withdrawal >= 0){
        std::cout << " index:" << this->_accountIndex << ";" \
        << "p_amount:" << this->_amount << ";" \
        << "withdrawal:" << withdrawal << ";";
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        Account::_totalNbWithdrawals += 1;
        std::cout << "amount:" << this->_amount << ";" \
        << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return true;
    }
    else {
        std::cout << " index:" << this->_accountIndex << ";" \
        << "p_amount:" << this->_amount << ";" \
        << "withdrawal:refused" << std::endl;
        return false;
    }
}

int Account::checkAmount(void) const{
    return this->_amount;
}

void Account::displayStatus(void) const{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";" \
    << "amount:" << this->_amount << ";" \
    << "deposits:" << this->_nbDeposits << ";" \
    << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
	std::time_t t = std::time(NULL);

	std::tm now = *localtime(&t);
	std::cout
			<< "["
			<< (now.tm_year + 1900)
			<< std::setfill('0')
			<< std::setw(2) << now.tm_mon + 1
			<< std::setw(2) << now.tm_mday << "_"
			<< std::setw(2) << now.tm_hour
			<< std::setw(2) << now.tm_min
			<< std::setw(2) << now.tm_sec
			<< "] ";
}