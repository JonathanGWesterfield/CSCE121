//
// Created by Jonathan G. Westerfield on 10/24/16.
//

#ifndef STOREBACKEND2_PRODUCT_H
#define STOREBACKEND2_PRODUCT_H

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
    Product(int productID, std::string productName, std::string productDescription);
    std::string getDescription() const;
    void setDescription(std::string description);
    std::string getName() const;
    int getID() const;
    int getNumberSold() const;
    double getTotalPaid() const;
    int getInventoryCount() const;
    void addShipment(int shipmentQuantity, double shipmentCost);
    void reduceInventory(int purchaseQuantity);
    double getPrice() const;
    bool operator==(Product& rhs) const;
    bool operator!=(Product &rhs) const;
};

std::ostream& operator<<(std::ostream& os, const Product& product);

#endif //STOREBACKEND2_PRODUCT_H
