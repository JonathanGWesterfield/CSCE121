#include <iostream>
#include "Product.h"

using namespace std;

int main() {
    Product p = Product(777,"WD Forty");
    cout << "ID: " << p.getID() << endl;
    p.setDescription("A lubricant resistant to high heat");
    cout << "Product Description: " << p.getDescription() << endl;
    cout << "Product Name: " << p.getName() << endl;
}