//
// Created by Jonathan G. Westerfield on 10/22/16.
//
#include "Store.h"
#include <iostream>

using namespace std;

Store::Store()
{
    this -> name = "Health and Safety Violation";
}
Store::Store(string name)
{
    this -> name = name;
}
string Store::getName()
{
    return name;
}
void Store::setName(string storeName)
{
    this -> name = storeName;
}
void Store::takeShipment(int productID, int quantity, double cost)
{

}
void Store::makePurchase(int customerID, int productID, int quantity)
{

}
void Store::takePayment(int customerID, double amount)
{

}
void Store::addProduct(int productID, string productName)
{
    Product prod(productID, productName);
}
string Store::listProducts()
{

}
void Store::addCustomer(int customerID, string name)
{
    Customer customer(name, customerID, true);
}