#include "Bank.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>
using namespace std;

void Bank::addCheckingAccount(int accountNumber, string name) {
	CheckingAccount* acct = new CheckingAccount(accountNumber, name);
	accounts.push_back(acct);
}

void Bank::addSavingsAccount(int accountNumber, string name, double interestRate) {
	SavingsAccount* acct = new SavingsAccount(accountNumber, name, interestRate);
	accounts.push_back(acct);
}

Account* Bank::getAccount(int accountNumber) {
	for (int i = 0; i < accounts.size(); ++i) {
		Account* a = accounts.at(i);
		if (a->getAccountNumber() == accountNumber) {
			return a;
		}
	}
	throw runtime_error("Invalid Account Number");
}

void Bank::printAccount(int accountNumber) {
	Account* a = getAccount(accountNumber);
	a->printAccount();
}

void Bank::printAccounts() {
	for (int i = 0; i < accounts.size(); ++i) {
		Account* acct = accounts.at(i);
		acct->printAccount();
		cout << endl;
	}
}

void Bank::makeDeposit(int accountNumber, double amount) {
	Account* a = getAccount(accountNumber);
	a->makeDeposit(amount);
}

void Bank::doWithdrawl(int accountNumber, double amount) {
	Account* a = getAccount(accountNumber);
	a->doWithdrawal(amount);
}
