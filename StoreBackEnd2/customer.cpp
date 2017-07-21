//
// Created by Jonathan G. Westerfield on 10/22/16.
//

#include "customer.h"
#include <iostream>
#include <string>
#include <stdexcept>


using namespace std;

Customer::Customer()
{
    this -> balance = 0;
}
Customer::Customer(int customerID, string customerName)
{
    this -> customerID = customerID;
    this -> name = customerName;
}
Customer::Customer(string customerName, int customerID, bool credit)
{
    this -> name = customerName;
    this -> customerID = customerID;
    this -> credit = credit;
    this -> balance = 0;
}
string Customer::getName() const
{
    return name;
}

void Customer::setName(string name)
{
    this -> name = name;
}

int Customer::getID() const
{
    return customerID;
}

bool Customer::getCredit() const
{
    return credit;
}

void Customer::setCredit(bool hasCredit)
{
    this -> credit = hasCredit;
}

double Customer::getBalance() const
{
    return balance;
}

void Customer::listProductsPurchased(std::ostream& os) const
{
    cout << "Products Purchased: " << endl;
    for(int i = 0; i < productsPurchased.size(); i++)
    {
        cout << productsPurchased.at(i) << endl;
        os << productsPurchased.at(i) << endl;
    }
}

void Customer::processPayment(double amount)
{
    if(amount < 0)
    {
        throw std::runtime_error("Cannot have a negative amount");
    }
    else
    {
        cout << "Transaction Authorized" << endl;
        balance += amount;
     }
}

void Customer::processPurchase(double amount, Product product)
{
    bool pastProduct = false;
    if(amount < 0)
        throw std::runtime_error("Cannot have a negative amount");

    if(balance < 0 || (balance - amount) < 0)
    {
        if(credit == true)
        {
            cout << "Transaction Authorized" << endl;
            balance -= amount;
        }
        else
        {
           throw std::runtime_error("Cannot have a negative balance without credit");
       }
    }
    else
    {
        cout << "Transaction Authorized" << endl;
        balance -= amount;
    }
    for(int i = 0; i < productsPurchased.size(); i++)
    {
        if(product == productsPurchased.at(i))
            pastProduct = true;
    }
    if(pastProduct == false)
        productsPurchased.push_back(product);
}

ostream& operator<<(std::ostream& os, const Customer& customer)
{
    os << " - Customer ID: " << customer.getID()<< endl;
    os << " - Name: " << customer.getName() << endl;
    os << " - Balance: " << customer.getBalance() << endl;
    if(customer.getCredit() == true)
        os << " - Credit: Yes" << endl;
    else
        os << " - Credit: No" << endl;

    //os << " - Description: " << product.getDescription() << endl;
    return os;
}

