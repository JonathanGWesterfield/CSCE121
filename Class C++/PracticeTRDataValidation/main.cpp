#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	cout << "How many elements in vector?" << endl;
	cin >> n;
	
	while(!cin.good())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n'); //clears the buffer
		
		cout << "Invalid input, enter number again" << endl;
		cin >> n;
	}
	vector<double> v(n);
	cout << "Enter values for list of numbers: " << endl;
	
	for(int i = 0; i < n; ++i)
	{
		cin >> v.at(i);
		while(!cin.good())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n'); //clears the buffer
		
			cout << "Invalid input for number " << i+1;
			cout << ", enter number again" << endl;
			cin >> v.at(i);
		}
		
	}
	
	cout << "Numbers in vector: " << endl;
	
	for(int i = 0; i < n; ++i)
	{
		cout << v.at(i) << " ";
	}
	cout << endl;
}