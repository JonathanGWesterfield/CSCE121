//
// Created by Jonathan G. Westerfield on 10/22/16.
//

#ifndef STOREBACKEND_PRODUCT_H
#define STOREBACKEND_PRODUCT_H
#include <iostream>

class Product
{
private:
    int productID;
    std::string name;
    std::string description;
    int inventory;
    int numSold;
    double totalPaid;
public:
    Product(int productID, std::string productName);
    std::string getDescription();
    void setDescription(std::string description);
    std::string getName();
    int getID();
    int getNumberSold();
    double getTotalPaid();
    int getInventoryCount();
};

#endif //STOREBACKEND_PRODUCT_H
