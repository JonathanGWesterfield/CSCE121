#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"
#include <string>

class CheckingAccount : public Account {
public:
	CheckingAccount(int accountNumber = 0, std::string name = "");
	// FIXME (2 b) uncomment following line
	//std::string getTypeName();
};


#endif
