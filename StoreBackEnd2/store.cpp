//
// Created by Jonathan G. Westerfield on 10/24/16.
//

#include "store.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

//std::vector<Customer> cust;
//std::vector<Product> prod;

Store::Store()
{
    this -> name = "Health and Safety Violation";
}
Store::Store(string name)
{
    this -> name = name;
}
string Store::getName() const
{
    return name;
}
void Store::setName(string storeName)
{
    this -> name = storeName;
}
void Store::takeShipment(int productID, int quantity, double cost)
{
    getProduct(productID).addShipment(quantity, cost);
}

void Store::makePurchase(int customerID, int productID, int quantity)
{
    getProduct(productID).reduceInventory(quantity);
    getCustomer(customerID).processPurchase(quantity * getProduct(productID).getPrice(),getProduct(productID));
}
void Store::listProducts() const
{
    for(int i = 0; i < prod.size(); i++)
    {
        cout << prod.at(i) << endl;
    }
}
void Store::listCustomers() const
{
    for(int i = 0; i < cust.size(); i++)
    {
        cout << cust.at(i) << endl;
    }
}
void Store::takePayment(int customerID, double amount)
{
    getCustomer(customerID).processPayment(amount);
}

Product& Store::getProduct(int productID)
{
    bool found = false;
    for(int i = 0; i < prod.size(); i++)
    {
        if(prod.at(i).getID() == productID)
        {
            cout << prod.at(i) << endl;
            return prod.at(i);
            found = true;
        }
    }
    if(!found)
        throw std::runtime_error("Product Not Found");
}
Customer& Store::getCustomer(int customerID)
{
    bool found = false;
    for(int i = 0; i < cust.size(); i++)
    {
        if(cust.at(i).getID() == customerID)
        {
            cout << cust.at(i) << endl;
            return cust.at(i);
            found = true;
        }
    }
    if(!found)
        throw std::runtime_error("Product Not Found");
}
void Store::addProduct(int productID, string productName)
{
    for(int i = 0; i < prod.size(); i++)
    {
        if(prod.at(i).getID() == productID)
            throw std::runtime_error("This product already exists");
    }
    prod.push_back(Product(productID, productName));
}
string Store::listProducts()
{
    ostringstream oss;
    if(prod.size() == 0)
    {
        oss << "No Products in Inventory" << endl;
        cout << "No Products in Inventory" << endl;
    }
    else
    {
        for(int i = 0; i < prod.size(); i++)
        {
            Product product = prod.at(i);
            oss << prod.at(i) << endl;
            cout << prod.at(i) << endl;
        }
    }
    return oss.str();
}
void Store::addCustomer(int customerID, string name)
{
    for(int i = 0; i < cust.size(); i++)
    {
        if(cust[i].getID() == customerID)
            throw std::runtime_error("This customer already exists");
    }
    cust.push_back(Customer(customerID, name));
}
