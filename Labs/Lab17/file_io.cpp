#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	//srand(time(NULL));

	//vector<int> nums{ 583, 249, 129, 938, 256, 765 };
	
	// When you uncomment this block, comment out the vector declaration/definition/initialization above
	vector<int> nums;
	// Hint: this is very similar to how the censor words were read in
	//       in the unnecessary censorship example.
	// Step 1: declare/define/initialize/open an input stream for file "nums.dat"
	ifstream numFile = ifstream("nums.dat");

	// Step 2: check if file opened successfully
	if (!numFile.is_open())
	{
		cout << "File could not be found or opened" << endl;
		return 1;
	}
	else
		cout << "File was found and is good." << endl;
	// Step 3: read data
	// if opened, then read values from file into vector nums
	int number;
	while (numFile >> number)
	{
		nums.push_back(number);
	}

	// hint: you can read data inside a while loop with condition infile >> a where a is an int type
	
	// Step 5: close (Do nothing will automatically close when stream variable is destroyed.)
	

	// Output values in vector
	for (int i = 0; i < nums.size(); ++i) {
		cout << setw(5) << nums.at(i);
		if ((i+1) % 5 == 0) cout << endl; // new line for each 5 numbers
	}
	cout << endl << endl;

	sort(nums.begin(), nums.end());

	// Steps 1 & 2: declare/define/initialize/open an output stream for file "stats.dat"

	ofstream outFile = ofstream("stats.dat");
	// Step 3: check if opened successfully

	if (!outFile.is_open())
	{
		cout << "Output file could not be opened" << endl;
		return 1;
	}
	else
		cout << "Output file opened successfully" << endl;

	double median = (nums.size() % 2) ? nums.at((nums.size() - 1) / 2) : (nums.at((nums.size() - 1) / 2) + nums.at((nums.size()) / 2)) / 2.0;
	// above probably needs a comment, but as a challenge figure out what's going on...

	// Step 4: write to stream (convert below to output to file stream instead of cout)
	outFile << "Min: " << nums.at(0) << endl;
	outFile << "Max: " << nums.at(nums.size()-1) << endl;
	outFile << "Median " << median << endl;

	// Step 5: close (Do nothing will automatically close when stream variable is destroyed.)

	system("pause");            // Uncomment for Visual Studio
}