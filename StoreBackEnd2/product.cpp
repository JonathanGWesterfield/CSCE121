//
// Created by Jonathan G. Westerfield on 10/24/16.
//

#include "product.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Product::Product(int productID, string name)
{
    this -> productID = productID;
    this -> name = name;
    this -> inventory = 0;
    this -> numSold = 0;
    this -> totalPaid = 0;
}
Product::Product(int productID, std::string productName, std::string description)
{
    this -> productID = productID;
    this -> name = name;
    this -> description = description;
    this -> inventory = 0;
    this -> numSold = 0;
    this -> totalPaid = 0;
}
std::string Product::getDescription() const
{
    return description;
}
void Product::setDescription(string description)
{
    this -> description = description;
}
std::string Product::getName() const
{
    return name;
}
int Product::getID() const
{
    return productID;
}
int Product::getNumberSold() const
{
    return numSold;
}
double Product::getTotalPaid() const
{
    return totalPaid;
}
int Product::getInventoryCount() const
{
    return inventory;
}

void Product::addShipment(int shipmentQuantity, double shipmentCost)
{

    if (shipmentQuantity < 0)
        throw std::runtime_error("Shipment Quantity cannot be negative");
    if(shipmentCost< 0)
        throw std::runtime_error("Shipment Cost cannot be negative");
    inventory += shipmentQuantity;
    totalPaid += shipmentCost;
}
void Product::reduceInventory(int purchaseQuantity)
{
    if (purchaseQuantity < 0)
        throw std::runtime_error("Purchase Quantity cannot be negative");
    if((inventory - purchaseQuantity) < 0)
        throw std::runtime_error("Inventory cannot be negative");
    inventory -= purchaseQuantity;
    numSold += purchaseQuantity;
}
double Product::getPrice() const
{
    double price = (totalPaid/((double)(inventory + numSold))) * 1.25;
    return price;
}
ostream& operator<<(ostream& os, const Product& product) {
    os << " - Product ID: " << product.getID()<< endl;
    os << " - Name: " << product.getName() << endl;
    os << " - Inventory: " << product.getInventoryCount() << endl;
    os << " - Total Paid: " << product.getTotalPaid();
    //os << " - Description: " << product.getDescription() << endl;
    return os;
}
bool Product::operator==(Product &rhs) const
{
    if(this -> getID() == rhs.getID())
        return true;
    if(this -> getName() == rhs.getName())
        return true;
    return false;
}
bool Product::operator!=(Product &rhs) const
{
    if(this -> getID() == rhs.getID())
    {
        if(this -> getName() == rhs.getName())
            return false;
    }
    return true;
}

