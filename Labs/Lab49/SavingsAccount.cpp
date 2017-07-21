#include "SavingsAccount.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(int accountNumber, string name, double interestRate) :
	Account(accountNumber, name) {
	accountType = SAVINGS;
	if (interestRate < 0) {
		throw runtime_error("Interest Rate must be positive.");
	}
	this->interestRate = interestRate;
}

// FIXME (2 b) uncomment following function
/*string SavingsAccount::getTypeName() {
	return "Savings";
}*/

void SavingsAccount::printDetails() {
	cout << "Interest Rate: " << interestRate << "%" << endl;
}

void SavingsAccount::processInterest() {
	setBalance(getBalance()*(1 + (interestRate / 100)));
}