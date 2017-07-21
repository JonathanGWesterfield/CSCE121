//
// Created by Jonathan G. Westerfield on 10/22/16.
//

#ifndef STOREBACKEND_STORE_H
#define STOREBACKEND_STORE_H

#include <iostream>
#include "Customer.h"
#include "Product.h"

class Store
{
private:
    //Product products;
    //Customer customers;
    std::string name;
    //std::string getProduct(int productID) : products;
    //std::string getCusomter(int customerID) : customers;
public:
    Store();
    Store(std::string name);
    std::string getName();
    void setName(std::string storeName);
    void takeShipment(int productID, int quantity, double cost);
    void makePurchase(int customerID, int productID, int quantity);
    void takePayment(int customerID, double amount);
    void addProduct(int productID, std::string productName);
    std::string listProducts();
    void addCustomer(int customerID, std::string name);
};
#endif //STOREBACKEND_STORE_H
