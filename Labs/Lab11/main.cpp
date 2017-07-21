#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
using namespace std;

int main() {
	char cont = 'y';
	const int w = 3;
	vector< vector<int> > tbl;
	while (cont == 'y') {
		tbl.clear();
		int num = -1;
		
		while (num < 1 || num > 9) { 
			cout << "Enter how many numbers for table (1-9): ";
			cin >> num;
			cout << endl << endl;
			if(num<1 || num > 9)
				;
		}
		// load vector
		// FIXME B: add/fix code so that this nested for loop fills
		//   vector with values of multiplication
		for (int i = 0; i < num; ++i) {
		    vector<int> row;
			for (int j = 0; j < num; ++j) {
			    row.push_back((j+1) * (i+1));
			}
			tbl.push_back(row);
		}

		// display normal
		// First row
		cout << " " << setw(w) << "|";
		for (int i = 0; i < num; ++i) {
			cout << setw(w) << (i + 1);
		}
		cout << endl;
		cout << "-" << setw(w) << "+";
		// Horizontal Separator
		for (int i = 0; i < num; ++i) {
			cout << setw(w) << "-";
		}
		cout << endl;
		// Rows of table
		// FIXME C: add code so that this nested for loop
		//   outputs the values in the vector
		for (int i = 0; i < num; ++i) {
		    cout << (i+1) << setw(w) << "|";
			for (int j = 0; j < num; ++j) {
			    cout << setw(w) << tbl.at(i).at(j);
			    // output value in vector
			}
			cout << endl;
		}
		cout << endl;

		// display reversed
		// First row
		cout << " " << setw(w) << "|";
		for (int i = num - 1; i >= 0; --i) {
			cout << setw(w) << (i + 1);
		}
		cout << endl;
		// Horizontal Separator
		cout << "-" << setw(w) << "+";
		for (int i = 0; i < num; ++i) {
			cout << setw(w) << "-";
		}
		cout << endl;
		// Rows of table
		// FIXME D: add code so that this nested for loop
		//   outputs the values in the vector
        //     HINT: should look like loop above
		for (int i = num - 1; i >= 0; --i) {
		    	cout << (i+1) << setw(w) << "|";
			for (int j = num - 1; j >= 0; --j) {
			    cout << setw(w) << tbl.at(i).at(j);
			    // output value in vector
			}
			cout << endl;
		}
		cout << endl;

		cout << "Do you want to do another? (y/n) ";
		cin >> cont;
		cout << endl << endl;
		cont = tolower(cont);
	}
	cout << "Goodbye!" << endl;
	//system("pause"); // Uncomment if you need for Visual Studio
    // comment out system("pause") for Vocareum
}
