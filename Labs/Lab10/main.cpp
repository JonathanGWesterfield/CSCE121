#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int i = -55; // set to random value
	cout << setfill('*') << setw(30) << "" << endl;
	
	cout << "Loop A (for version)" << endl;
	for (i = 0; i<5; i++) { //(initialization; termination condition; update)
		cout << i << endl;
	}

	cout << setfill('*') << setw(30) << "" << endl;
	cout << "Loop A (while version)" << endl;
	// Add while loop code, don't forget initialization, termination condition and update

	cout << setfill('*') << setw(30) << "" << endl;
	cout << "Loop A (do while version)" << endl;
	// Add do while loop code, don't forget initialization, termination condition and update

	cout << endl << endl; //***********************************************************************
	cout << setfill('*') << setw(30) << "" << endl;

	cout << "Loop B (while version)" << endl;
	i = 0; // initialization
	while (i < 10) { // termination condition
		cout << "Enter a number less than 10 (Greater than 10 to exit):" << endl;
		cin >> i; // update
		cout << "Number: " << i << endl;
	}

	cout << setfill('*') << setw(30) << "" << endl;

	cout << "Loop B (do while version)" << endl;
	// Add do while loop code, don't forget initialization, termination condition and update
	 
	cout << setfill('*') << setw(30) << "" << endl;

	cout << "Loop B (for version)" << endl;
	// Add for loop code, don't forget initialization, termination condition and update 
	// Note: initialization, termination condition and update should 
	//       all be in the () after the 'for' keyword!

	cout << endl << endl; //***********************************************************************
	cout << setfill('*') << setw(30) << "" << endl;

	cout << "Loop C (do while version)" << endl;
	i = 20;  // initialization
	do {
		cout << i * 2 << endl; // output
		i -= 2; // update
	} while (i>10); // termination condition
	
	cout << setfill('*') << setw(30) << "" << endl;

	cout << "Loop C (while version)" << endl;
	// Add while loop code, don't forget initialization, termination condition and update
	
	cout << setfill('*') << setw(30) << "" << endl;

	cout << "Loop C (for version)" << endl;
	// Add for loop code, don't forget initialization, termination condition and update 
	// Note: initialization, termination condition and update should 
	//       all be in the () after the 'for' keyword!

	cout << setfill('*') << setw(30) << "" << endl;

}      