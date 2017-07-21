//
// Created by Jonathan G. Westerfield on 11/17/16.
//

//#ifndef TEMPERATURE_QUERIES_TEMPERATUREDB_H
//#define TEMPERATURE_QUERIES_TEMPERATUREDB_H
#ifndef TEMP_DB
#define TEMP_DB

#include <string>
#include "linkedlist.h"

class TemperatureDatabase {
public:
    // Default constructor/destructor. Modify them if you need to.
    TemperatureDatabase() {}
    ~TemperatureDatabase() {}

    // The two functions below are required

    // Read the temperature records from the data file and populate the linked list
    void loadData(const std::string& data_file);

    void printMethod() const;

    // Read the queries from the query file and perform a series of queries
    void performQuery(const std::string& query_filename);

private:
    // Linked list to store the temperature records. You need to properly populate
    // this link list.
    LinkedList records;
    LinkedList query;

    // You can add any private member variables/functions you feel useful in this class.
};

#endif  // TEMP_DB


// #endif //TEMPERATURE_QUERIES_TEMPERATUREDB_H
