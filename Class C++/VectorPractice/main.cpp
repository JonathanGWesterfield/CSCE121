#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main()
{
	vector<vector<int> > v;
	int NUM_VALS = 5;
	int RANGE = 10000;
	
	int rseed = 7;
	
	for(unsigned int i = 0; i < NUM_VALS; ++i)
	{
		vector <int> row;
		for(int j = 0; j < NUM_VALS; ++j)
		{
			int val = rand() % RANGE;
			cout << val << endl;
			row.push_back(val);
		}
		v.push_back(row);
	}
	
	cout << "OUTPUT Vector" << endl;
	for(int i = 0; i < NUM_VALS; ++i)
	{
		for(int j = 0; j < NUM_VALS; ++j)
		{
			cout << setw(6) << v.at(i).at(j) << " ";
		}
		cout << endl;
	}
	
	return 0;
}