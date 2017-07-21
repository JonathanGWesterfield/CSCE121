//
// Created by Jonathan G. Westerfield on 10/22/16.
//

#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(string customerName, int customerID, bool credit)
{
    this -> customerName = customerName;
    this -> customerID = customerID;
    this -> credit = credit;
}
string Customer::getName()
{
    return customerName;
}

/*void Customer::setName(string name)
{
    this -> name = name;
}*/

int Customer::getID()
{
    return customerID;
}

bool Customer::getCredit()
{
    return credit;
}

void Customer::setCredit(bool hasCredit)
{
    hasCredit = hasCredit;
}

double Customer::getBalance()
{
    return balance;
}

void Customer::listProductsPurchased(Product productsPurchased)
{
    Product prod = productsPurchased;
    cout << "Customer has purchased: " << endl;
    cout << "Product ID: " << prod.getID() << "  ";
    cout << "Product Name: " << prod.getName() << endl;
}

void Customer::processPayment(double amount)
{
    if(balance < 0 || (balance - amount) < 0)
    {
        if(credit ==  true)
        {
            cout << "Transaction Authorized" << endl;
            // balance -= amount;
        }
        else
        {
            cerr << "Cannot have a negative balance without credit" << endl;
            cerr << "Transaction Denied" << endl;
        }
    }
    else
    {
        cout << "Transaction Authorized" << endl;
        // balance -= amount;
    }
}

void Customer::processPurchase(double amount, Product product)
{

}


