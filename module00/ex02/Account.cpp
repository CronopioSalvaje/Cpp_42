#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(void)
{
	_nbAccounts++;
	this->_amount = 0;
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}
Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
    this->_totalAmount += initial_deposit;
    this->_accountIndex = _nbAccounts;
    _nbAccounts++;   
	//_totalNbDeposits++;
	//this->_nbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
	_totalAmount -= this->checkAmount();
	_totalNbWithdrawals++;
	_nbAccounts--;
}

void Account::makeDeposit(int deposit)
{
	this->_totalAmount+= deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    this->_amount += deposit;
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposit:" << this->_nbDeposits << ";" << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
	if (this->_amount - withdrawal > 0)
	{
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
        std::cout << "index:" << this->_accountIndex << ";";
        std::cout << "p_amount:" << this->_amount << ";";
        std::cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
        _totalAmount -=withdrawal;
        std::cout << "amount:" << this->_amount << ";";
        std::cout << "nb_withdrawal:" <<this->_nbWithdrawals << std::endl;   
		return (true);
	}
    else
    {
 
        std::cout << "index:" << this->_accountIndex << ";";
        std::cout << "p_amount:" << this->_amount << ";";
        std::cout << "withdrawal:refused" << std::endl;   
    }
	return (false);
}
int Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
    }

void Account::_displayTimestamp(void)
{
    std::time_t time = std::time(NULL);
    std::tm* timeInfo = std::localtime(&time);
 
	std::cout << "[";
    std::cout << 1900 + timeInfo->tm_year;
    if (timeInfo->tm_mon + 1 < 10)
        std::cout << "0";
    std::cout << timeInfo->tm_mon + 1;
    if (timeInfo->tm_mday < 10)
        std::cout << "0";
    std::cout << timeInfo->tm_mday << "_";
    if (timeInfo->tm_hour < 10)
        std::cout << "0";
    std::cout << timeInfo->tm_hour;
    if (timeInfo->tm_min < 10)
        std::cout << "0";
    std::cout << timeInfo->tm_min;
    if (timeInfo->tm_sec < 10)
        std::cout << "0";
    std::cout << timeInfo->tm_sec;
    std::cout << "] ";
}