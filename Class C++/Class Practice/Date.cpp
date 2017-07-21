//
// Created by Jonathan G. Westerfield on 10/20/16.
//
#include "Date.h"
#include <iostream>

using namespace std;

void Date::printDate()
{
    cout << day << endl;
}

void Date::setDay(int day)
{
    this -> day = day;
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

void Date::setMonth(int month)
{
    if(month < 1  || month > 12)
    {
        throw runtime_error("Invalid month value");
    }
    this -> month = month;
}

