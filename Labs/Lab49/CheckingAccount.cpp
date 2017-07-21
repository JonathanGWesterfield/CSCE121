#include "CheckingAccount.h"
#include <iostream>
using namespace std;

CheckingAccount::CheckingAccount
	(int accountNumber, string name) :
	Account(accountNumber, name)  {
	accountType = CHECKING;
}

// FIXME (2 b) uncomment following function
/*string CheckingAccount::getTypeName() {
	return "Checking";
}*/
