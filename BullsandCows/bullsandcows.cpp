#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool contains_duplicate(vector<int> Vec)
{
	sort(Vec.begin(), Vec.end());
	return adjacent_find(Vec.begin(), Vec.end()) != Vec.end();
}

int main()
{
    int numVals; // the length of the generated code
    int numDigits; // the length of the user input 
    int guessCode; //the guess the user inputs
    int bulls = 0;
    int cows = 0;
    bool valid = false; // decides if the length desired by user is valid
	bool uniqueCheck = false; // decides if the users input has repeating numbers
    vector<int> codeVec; //the random generated code
	vector<int> guessCodeVec; // the vector of user input 
	vector<int> guessCodeCheck; // checks to make sure the user inputs non repeating number
	bool gameContinue = false;

    while(!valid) {
		cout << "Enter number of digits in code (0, 3, 4, or 5): ";
		cin >> numVals;
		if(numVals == 0 || numVals == 3 || numVals == 4 || numVals == 5)
			valid = true;
		else
			cout << "ERROR: VALUE MUST BE 0, 3, 4, OR 5" << endl << endl;
		}

	if(numVals != 0) {
		srand(time(0)); // Seed the random number generator

		for(int i = 0; i < 10; ++i) {
			random_shuffle(codeVec.begin(), codeVec.end());
			codeVec.push_back(i);
		}
		valid = false;
		while(!valid)
		{
			cout << "Number to guess: ";
			for(int i = 0; i < numVals; ++i) {
				cout << codeVec.at(i);
		}

		cout << endl << "Enter guess: ";
		cin >> guessCode;
		if(guessCode >= 0 && guessCode < 10)
			numDigits = 1;
		else if(guessCode >= 10 && guessCode < 99)
			numDigits = 2;
		else if(guessCode >= 100 && guessCode < 1000)
			numDigits = 3;
		else if(guessCode >= 1000 && guessCode < 10000)
			numDigits = 4;
		else if(guessCode >= 10000 && guessCode < 100000)
			numDigits = 5;
	
		//gets the vector of what the user guesses
		for(int i = numVals - 1; i >= 0; i--) {
			int indexNum = guessCode % 10;
			guessCodeVec.push_back(indexNum);
			guessCode /= 10;
		}	
		
		
		if(numVals > numDigits) {
			int numZeros = numVals - numDigits;
			int count = 1;
			while(count < numZeros)
			{
				guessCodeVec.push_back(0);
				count++;
			}
		}
		reverse(guessCodeVec.begin(), guessCodeVec.end());
		if(contains_duplicate(guessCodeVec))
		{
			cout << "Number cannot have repeated digits!" << endl;
			continue;
		}
		
		valid = true;
	}
		
		for(int i = 0; i < guessCodeVec.size(); i++) {
			cout << guessCodeVec.at(i);
		}
		cout << endl;
			
		for(int i = 0; i < guessCodeVec.size(); i++)
		{
			if(codeVec.at(i) == guessCodeVec.at(i))
			{
				bulls += 1;
				cows -= 1;
			}
			for(int j = 0; j < codeVec.size(); j++)
			{
				if(guessCodeVec.at(i) == codeVec.at(j))
				{
					cows += 1;
				}
			}
		}
		cout << "bulls :" << bulls << endl << "cows: " << cows << endl;
		//outputs guessCodeVec
		for(int i = 0; i < guessCodeVec.size(); i++) {
			cout << guessCodeVec.at(i);
		}
		cout << endl;


	// this is for if the user enter 0
    } else {
		while(bulls != 4) {
			int userNumDigits; // number of digits the user wants
			cout << "Enter Code: ";
			cin >> guessCode;
			if(guessCode >= 0 && guessCode < 10)
				numDigits = 1;
			else if(guessCode >= 10 && guessCode < 99)
				numDigits = 2;
			else if(guessCode >= 100 && guessCode < 1000)
				numDigits = 3;
			else if(guessCode >= 1000 && guessCode < 10000)
				numDigits = 4;
			else if(guessCode >= 10000 && guessCode < 100000)
				numDigits = 5;

			cout << "Enter number of digits in code: ";
			cin >> userNumDigits; // number of digits in the actual user input
			//vector<int> guessCodeVec;
			for(int i = numDigits - 1; i >= 0; i--) {
				int indexNum = guessCode % 10;
				guessCodeVec.push_back(indexNum);
				guessCode /= 10;
			}

			reverse(guessCodeVec.begin(), guessCodeVec.end());
			if(userNumDigits > numDigits) {
				int numZeros = userNumDigits - numDigits;
				for(int i = 0; i < numZeros; ++i) {
					guessCodeVec.insert(guessCodeVec.begin(), 0);
				}
			}

			for(int i = 0; i < guessCodeVec.size(); i++) {
				cout << guessCodeVec.at(i);
			}
			cout << endl;
		}
    }
}