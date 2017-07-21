#include "temperaturedb.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        cout << "Usage: " << argv[0] << " data_file query_file" << endl;
        return 1;
    }
    else
    {
        string argv1 = "/Users/JonathanWesterfield/Documents/CSCE 121/Temperature Queries/s050_TX-2000-2015.dat";
        string argv2 = "/Users/JonathanWesterfield/Documents/CSCE 121/Temperature Queries/queries-2000s.dat";
        TemperatureDatabase database;
        LinkedList list;
        database.loadData(argv1);
        database.performQuery(argv2);

        // database.printMethod();
    }

}
