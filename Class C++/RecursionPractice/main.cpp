#include <iostream>
using namespace std;

int fib(int num)
{
	if(num == 0)
	{
		return 0;
	}
	else if(num == 1) // ((num==0) || (num==1))
	{
		return 1;
	}
	return fib(num - 1) + fib(num - 2);
}

int main()
{
	int num;
	cout << "Enter a number: ";
	cin >> num;
	
	cout << "F(" << num << ") = ";
	cout << fib(num);
}