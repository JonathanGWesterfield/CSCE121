//
// Created by Jonathan G. Westerfield on 10/24/16.
//

#ifndef STOREBACKEND2_STORE_H
#define STOREBACKEND2_STORE_H

#include <iostream>
#include <vector>
#include <sstream>
#include "customer.h"
#include "product.h"

class Store
{
private:
    //Product products;
    //Customer customers;
    std::string name;
    std::vector<Customer> cust;
    std::vector<Product> prod;
    //std::string getProduct(int productID) : products;
    //std::string getCustomer(int customerID) : customers;
public:
    Store();
    Store(std::string name);
    std::string getName() const;
    void setName(std::string storeName);
    void takeShipment(int productID, int quantity, double cost);
    void makePurchase(int customerID, int productID, int quantity);
    void addProduct(int productID, std::string productName);
    std::string listProducts();
    void addCustomer(int customerID, std::string name);
    void listProducts() const;
    void listCustomers() const;
    Product& getProduct(int productID);
    Customer& getCustomer(int customerID);
    void takePayment(int customerID, double amount);
};

#endif //STOREBACKEND2_STORE_H
