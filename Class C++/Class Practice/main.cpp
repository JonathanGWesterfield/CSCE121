#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    Date date;
    date.setDay(20);
    cout << "Day: " << date.getDay() << endl;
    date.printDate();
    cout << endl;

}