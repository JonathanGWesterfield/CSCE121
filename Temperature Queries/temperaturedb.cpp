//
// Created by Jonathan G. Westerfield on 11/17/16.
//

#include "temperaturedb.h"
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdexcept>
#include <string>
using namespace std;

void TemperatureDatabase::loadData(const string& filename)
{
    int location;
    int year;
    int month;
    double temperature; // THIS IS IN CELSIUS
    string temperaryString;
    ifstream Data;
    Data.open(filename);

    if (!Data.is_open())
    {
        // If file could not be found or opened then the
        // program shuts down
        cerr << "ERROR: FILE " << filename << " COUlD NOT BE OPENED" << endl;
        cerr << "EXITING PROGRAM" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Temperature file found and good" << endl;
        while(getline(Data, temperaryString))
        {
            stringstream ss;
            ss << temperaryString;
            ss >> location >> year >> month >> temperature;

            if((month < 1) || (month > 12))
            {
                throw std::runtime_error("Invalid month");
            }
            if((year < 1800))
            {
                throw std::runtime_error("No records before this year");
            }
            if(((temperature < -50.0) || (temperature > 50.0)) && temperature != -99.99)
            {
                throw std::runtime_error("Invalid Temperature: must be between -50 and 50 degrees celsius");
            }

            if(temperature != -99.99)
            {
                records.insert(location, year, month, temperature);
            }
        }
        Data.close();
    }
    return;
}

void TemperatureDatabase::printMethod() const
{
    records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
    // Implement this function
    string temperaryString;
    int location;
    int year1;
    int year2;
    string AVG = "AVG";
    string MODE = "MODE";
    string requestType;

    ifstream queryData;
    queryData.open(filename);

    // opens query file to be read
    if (!queryData.is_open())
    {
        // If file could not be found or opened then the
        // program shuts down
        cerr << "ERROR: FILE " << filename << " COUlD NOT BE OPENED" << endl;
        cerr << "EXITING PROGRAM" << endl;
        exit(EXIT_FAILURE);
    } else {
        cout << "Query file found and good" << endl;
    }

    // opens output file to store results of query operation
    ofstream output;
    output.open("Test-results-2.dat");
    if (!queryData.is_open())
    {
        // If file could not be found or opened then the
        // program shuts down
        cerr << "ERROR: FILE " << filename << " COUlD NOT BE CREATED" << endl;
        cerr << "EXITING PROGRAM" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "Results.dat file opened for writing" << endl;
        while(getline(queryData, temperaryString))
        {
            stringstream ss;
            ss << temperaryString;
            ss >> location >> requestType >> year1 >> year2;
            // cout << "Location: " << location << "\nRequest Type: " << requestType << endl;
            // cout << "Year 1: " << year1 << "\nYear 2: " << year2 << endl;
            if((year1 < 1800) || (year1 > 2016) || (year2 < 1800) || (year2 > 2016)
                    || (year2 < year1))
            {
                throw std::runtime_error("Invalid years");
            }
            if((requestType != AVG) && (requestType != MODE))
            {
                throw std::runtime_error("Invalid Operation Request\nMust either be AVG or MODE");
            }
            if((year1 <= year2) && (requestType == AVG))
            {
                double temperatureAverage = records.tempAverage(location, year1, year2);
                if(temperatureAverage == -99.99)
                {
                    // cout << temperatureAverage << endl;
                    output << location << " " << year1 << " " << year2 << " ";
                    output << requestType << " unknown" << endl;
                }
                else
                {
                    // cout << temperatureAverage << endl;
                    output << location << " " << year1 << " " << year2 << " ";
                    output << requestType << " " << temperatureAverage << endl;
                }
            }
            if((year1 <= year2) && (requestType == MODE))
            {
                double tempMode = records.tempMode(location, year1, year2);
                if(tempMode == -99.99)
                {
                    // cout << "TempMODE: " << tempMode << endl;
                    // cout << "Temperature Mode: " << tempMode << endl;
                    output << location << " " << year1 << " " << year2 << " ";
                    output << requestType << " unknown" << endl;
                }
                else
                {
                    // cout << "Temperature Mode: " << tempMode << endl;
                    output << location << " " << year1 << " " << year2 << " ";
                    output << requestType << " " << round(tempMode) << endl;
                }
            }
        }
    }
    output.close();


}

