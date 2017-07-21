#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector <int> v;
	const int SIZE = 100;
	const int RANGE = 200;
	int rseed = 5;
	srand(rseed);

	for (int i = 0; i < SIZE; ++i) {
		v.push_back(rand() % RANGE);
	}
	//sort(v.begin(), v.end());
	
	cout << "unsorted: " << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << "[" << i << "]" <<v.at(i) << endl;
	}
	
	for (int i = 0; i < v.size() - 1; ++i)
	{
		int smallest = i;
		
		for(int j = i + 1; j < v.size(); ++j)
		{
			if(v.at(j) < v.at(smallest))
			{
				smallest = j;
			}
		}
		int temp = v.at(i);
		v.at(i) = v.at(smallest);
		v.at(smallest) = temp;
	}
	
	cout << endl << "sorted: " << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << "[" << i << "]" <<v.at(i) << endl;
	}
	return 0;
}