#include "Account.hpp"
#include "print_utils.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::displayAccountsInfos(void)
{
	print_timestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:"
			  << _totalAmount << ";deposits:"
			  << _totalNbDeposits << ";withdrawals:"
			  << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	print_timestamp();
	print_index(this->_accountIndex);
	print_amount(this->_amount);
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits = deposit;
}

void Account::displayStatus(void) const
{
	print_timestamp();
	print_index(this->_accountIndex);
	print_amount(this->_amount);
	print_deposits(this->_nbDeposits);
	print_withdrawals(this->_nbWithdrawals);
	std::cout << std::endl;
}
