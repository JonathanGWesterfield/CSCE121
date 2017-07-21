#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include <string>

class Account {
	double balance;
	int accountNumber;
	std::string owner;
public:
	enum type
	{
		NONE, CHECKING, SAVINGS
	};
	Account(int accountNumber = 0, std::string name = "");
	void virtual fake() {};  // let's program compile before FIXME statements are addressed
	void makeDeposit(double amount);
	void doWithdrawal(double amount);
	void setBalance(double balance);
	double getBalance();
	void setAccountNumber(int accountNumber);
	int getAccountNumber();
	void setOwner(std::string ownerName);
	std::string getOwner();
	void printAccount();
	type getType();

	// FIXME (1) Add virtual before void on next line
	void printDetails();

	// FIXME (2 a) Uncomment following line
	//virtual std::string getTypeName() = 0;

protected:
	type accountType;
};

#endif
