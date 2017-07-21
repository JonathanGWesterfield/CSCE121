//
// Created by Jonathan G. Westerfield on 10/22/16.
//

#ifndef STOREBACKEND_CUSTOMER_H
#define STOREBACKEND_CUSTOMER_H
#include <iostream>
#include "Product.h"

class Customer
{
private:
    int customerID;
    std::string customerName;
    bool credit;
    double balance;
    //Product productsPurchased;
public:
    Customer(std::string name, int customerID, bool credit);
    std::string getName();
    void setName(std::string name);
    int getID();
    bool getCredit();
    void setCredit(bool hasCredit);
    double getBalance();
    void listProductsPurchased(Product productsPurchased);
    void processPayment(double amount);
    void processPurchase(double amount, Product product);
};
#endif //STOREBACKEND_CUSTOMER_H
