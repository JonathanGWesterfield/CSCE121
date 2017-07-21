//
// Created by Jonathan G. Westerfield on 10/24/16.
//

#ifndef STOREBACKEND2_CUSTOMER_H
#define STOREBACKEND2_CUSTOMER_H

#include <iostream>
#include <vector>
#include "product.h"

class Customer
{
private:
    int customerID;
    std::string name;
    bool credit;
    double balance;
    std::vector<Product> productsPurchased;
    //Product productsPurchased;
public:
    Customer();
    Customer(int customerID, std::string customerName);
    Customer(std::string name, int customerID, bool credit);
    std::string getName() const;
    void setName(std::string name);
    int getID() const;
    bool getCredit() const;
    void setCredit(bool hasCredit);
    double getBalance() const;
    void listProductsPurchased(std::ostream& os) const;
    void processPayment(double amount);
    void processPurchase(double amount, Product product);
};

std::ostream& operator<<(std::ostream& os, const Customer& customer);

#endif //STOREBACKEND2_CUSTOMER_H
