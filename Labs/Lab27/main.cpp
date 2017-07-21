#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

/* Globals */
const int NUM_VALUES = 10;
const int RANGE = 100;

/* Function Declarations */
vector<int> loadVector(int numValues, int range);
// Update below function declaration to take a default boolean parameter called reverse
void printVector(const vector<int>& num, bool reverse);

/*
Main Function
*/
int main() {
	srand(time(NULL));
	vector<int> nums = loadVector(NUM_VALUES, RANGE);
	bool reverse = false;
	

	cout << "Printed from index 0 to (size()-1), normal: " << endl;
	printVector(nums, reverse); // do not alter arguments after adding default parameter
	cout << endl;

	reverse = true;
	cout << "Printed from index (size()-1) to 0, reversed: " << endl;
	printVector(nums, reverse); // add argument so that it prints in reverse
	cout << endl;

	//system("pause");
}

// Load vector with indicated number of values from 0 to range-1
vector<int> loadVector(int numValues, int range) {
	vector<int> values;
	for (int i = 0; i < numValues; i++) {
		int val = rand() % range;
		values.push_back(val);
	}
	sort(values.begin(), values.end());
	return values;
}

// Update below function to take a default boolean parameter called reverse
//  When reverse is false, the vector is printed from index 0 to index size()-1
//  When reverse is true,  the vector is printed from index index size()-1 to 0
void printVector(const vector<int>& nums, bool reverse) {
	if(reverse == false) {
		for (int i = 0; i < nums.size(); i++) {
			cout << nums.at(i) << endl;
		}
	} else {
		for(int i = nums.size() - 1; i >= 0; i--) {
			cout << nums.at(i) << endl;
		}
	}
	cout << endl << endl;
}
