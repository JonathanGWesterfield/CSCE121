//
// Created by Jonathan G. Westerfield on 11/17/16.
//

#ifndef TEMPERATURE_QUERIES_NODE_H
#define TEMPERATURE_QUERIES_NODE_H

const int currentYear = 2016;

// Include the header file for the data struct/class if you use one.
// For example, if you have a data class in data.h, put
//  #include "data.h"
// below.

struct Node {
    // Add your member variable for the data fields here.
    // You can use an extra struct/class for storing the data. In that case, put
    // your definition of the data class in a separate header file, for example:
    // data.h

    int location;
    int year;
    int month;
    double temperature;
    int year1;
    int year2;
    std::string requestType;

    Node* next; // Pointer to the next node in the linked list

    // Default constructor
    Node() : next(nullptr)
    {
        // Initialize your data members properly inside the function body
        location = 410120;
        year = 1893;
        month = 1;
        temperature = -99.99;
    }

    int getLocation()
    {
        return location;
    }
    int getYear()
    {
        return year;
    }
    int getMonth()
    {
        return month;
    }
    double getTemperature()
    {
        return temperature;
    }

    Node(int location, int year, int month, double temperature) : next(nullptr)
    {
        this -> location = location;
        this -> year = year;
        this -> month = month;
        this -> temperature = temperature;
        // Initialize your data members properly inside the function body
    }

    // The function below is written. Do not modify it
    virtual ~Node() {}
};

//#endif

#endif //TEMPERATURE_QUERIES_NODE_H
