#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main() {
    // get a seed value for the pseudo-random number generator
    cout << "Enter seed value: ";
	int rseed;
    cin >> rseed;
    srand(rseed);
	cout << endl;

    // define constants for random values
    const int NUM_VALUES = 100;
    const int RANGE = 10000;

    // populate a vector with random values
    vector<int> values;
    for (int i = 0; i < NUM_VALUES; i++) {
        int val = rand() % RANGE;
        values.push_back(val);
    }

    // iterate through vector and print values
    // COMMENT OUT OR REMOVE THIS FOR LOOP FOR YOUR VOCAREUM SUBMISSION
    //for (int i = 0; i < NUM_VALUES; i++) {
    //    cout << setw(5) << values.at(i);
     //   if ((i+1)%10==0) cout << endl; // new line every 10 numbers
		// For fun, change i+1 to just i above, run and
		//    see how that affects the output
   // }
    cout << endl;

    int min, max;
    double avg, sum;
	
	min = values.at(0);
	for(int i = 0; i < values.size(); ++i)
	{
		if(values.at(i) > max)
		{
			max = values.at(i);
		}
		else if(values.at(i)< min)
		{
			min = values.at(i);
		}
	}
	
	for(int i = 0; i < values.size() -1; i++)
	{
		sum = sum + values.at(i);
	}
	
	avg = sum / values.size();
		
    
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Average: " << avg << endl;

    //system("pause");            // Uncomment for Visual Studio
} 