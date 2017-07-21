#include <iostream>
#include "Store.h"
#include <stdexcept>

using namespace std;

int main() {
    Store s("Aggie Stuff");
    s.addProduct(123, "Aggie hat");
    s.addCustomer(444, "Ole Sarge");
    s.addCustomer(555, "Rev");
    try {
        Customer c1 = Customer(123, "Ol Rock");
        //c1.setCredit(true);
        s.makePurchase(444, 123, 4);

        Customer c2 = Customer(123, "Big Al");
        c2.processPayment(1500);
        string str = s.listProducts();
        cout << str;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}