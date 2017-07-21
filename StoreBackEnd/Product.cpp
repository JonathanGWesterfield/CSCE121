//
// Created by Jonathan G. Westerfield on 10/22/16.
//
#include "Product.h"
#include <iostream>

using namespace std;

Product::Product(int productID, string name)
{
    this -> productID = productID;
    this -> name = name;

}
std::string Product::getDescription()
{
    return description;
}
void Product::setDescription(string description)
{
    this -> description = description;
}
std::string Product::getName()
{
    return name;
}
int Product::getID()
{
    return productID;
}
int Product::getNumberSold()
{
    return numSold;
}
double Product::getTotalPaid()
{
    return totalPaid;
}
int Product::getInventoryCount()
{
    return inventory;
}
