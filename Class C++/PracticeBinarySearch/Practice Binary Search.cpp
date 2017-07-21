#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;
	const int SIZE = 10;
	const int RANGE = 20;
	int rseed = 5;
	srand(rseed);
	
	for(int i = 0; i< size; ++i)
	{
		v.push_back(rand(SIZE) % RANGE);
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); ++i)
	{
		cout << v.at(i) << endl;
	}
	return 0;
}