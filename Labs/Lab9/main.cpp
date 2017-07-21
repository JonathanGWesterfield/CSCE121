#include <iostream>

using namespace std;
int main(int argc, char **argv)
{
	int chessBoard = 8;
	int sizeBoard = chessBoard * chessBoard;
	long double grainWheat = 1;
	double totalWheat;
	
	//cout<< fixed;
	//cout.precision(10);
	cout << "[" << "1] " << grainWheat <<" grains" << endl;
	
	for(int i = 0;i<=16385; i++)
	{
		grainWheat = grainWheat * 2;
		cout << "[" << (i + 2) << "] " << grainWheat <<" grains" << endl;
		
	}
	
	return 0;
}
