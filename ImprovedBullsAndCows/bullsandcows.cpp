#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool contains_duplicate(string Vec)
{
	sort(Vec.begin(), Vec.end());
	return adjacent_find(Vec.begin(), Vec.end()) != Vec.end();
}

string randomNumberGenerator(int vectorSize)
{
	srand(time(0)); // Seed the random number generator
	string possibleNums = "123456789";
	random_shuffle(possibleNums.begin(), possibleNums.end());
	string Code = possibleNums.substr(0, vectorSize);
	return Code;
}

string addBeginningZero(string guessCode, int numVals)
{
	int numZeros = numVals - guessCode.length();
	if(numZeros == 1)
	{
		guessCode = guessCode.insert(0,"0");
	}
	else if(numZeros > 1)
	{
		for(int i = 0; i < numZeros; i++)
		{
			guessCode = guessCode.insert(0,"0");
		}
		// will insert 2 zeros which will make the program output an error
		// in the game345 method
	}
	return guessCode;
}

void game345(int numVals)
{
	int bulls = 0;
    int cows = 0;
	string codeVec; //the random generated code
	
	codeVec = randomNumberGenerator(numVals);
	cout << "Number to guess: " << codeVec << endl;
	
	string possibleNums = "123456789";
	string guessCode; //the guess the user inputs
	
	cin.ignore(numeric_limits <streamsize>::max(), '\n'); //clears buffer to allow reading
	while (cout << "Number to guess: ", getline(cin, guessCode))
	{
		if(guessCode.length() < numVals)
		{
			guessCode = addBeginningZero(guessCode, numVals);// will send to method that adds a leading zero
		}
		if (contains_duplicate(guessCode))
		{
			cout << guessCode << "Each number must be different. " << endl;
			continue;
		}
		for(int i = 0; i < guessCode.length(); i++)
		{
			if(codeVec.at(i) == guessCode.at(i))
			{
				bulls++;
				cows --;
			}
			for(int j = 0; j < codeVec.length(); j++)
			{
				if(guessCode.at(i) == codeVec.at(j))
				{
					cows++;
				}
			}
		}
		
		if(bulls == codeVec.length())
		{
			cout << bulls << " bulls - " << guessCode << " is Correct!" << endl;
			break;
		}
		else
		{
			cout <<  bulls << " bulls " << endl  << cows << " cows"<< endl;
		}
			
		bulls = 0;
		cows = 0;
		
	}
}

void gameZero()
{
	string codeVec;
	string guessCode;
	int bulls = 0;
	int cows = 0;
	int numVals;
	
	cout << "Enter code: ";
	cin >> codeVec;
	
	cout << "Enter number of digits in code: ";
	cin >> numVals;
	
	if(numVals > codeVec.length())
	{
		codeVec = addBeginningZero(codeVec, numVals);
	}
	
	cout << "Number to guess: " << codeVec << endl;
	
	cin.ignore(numeric_limits <streamsize>::max(), '\n'); //clears buffer to allow reading
	while (cout << "Number to guess: ", getline(cin, guessCode))
	{
		if(guessCode.length() < numVals)
		{
			guessCode = addBeginningZero(guessCode, numVals);// will send to method that adds a leading zero
		}
		if (contains_duplicate(guessCode))
		{
			cout << guessCode << " Each number must be different." << endl;
			continue;
		}
		for(int i = 0; i < guessCode.length(); i++)
		{
			if(codeVec.at(i) == guessCode.at(i))
			{
				bulls++;
				cows --;
			}
			for(int j = 0; j < codeVec.length(); j++)
			{
				if(guessCode.at(i) == codeVec.at(j))
				{
					cows++;
				}
			}
		}
		
		if(bulls == codeVec.length())
		{
			cout << bulls << " bulls - " << guessCode << " is Correct!" << endl;
			break;
		}
		else
		{
			cout <<  bulls << " bulls " << endl  << cows << " cows"<< endl;
		}
			
		bulls = 0;
		cows = 0;
		
	}
}

int main()
{
	int numVals; // the length of the generated code
    int numDigits; // the length of the user input 

    bool valid = false; // decides if the length desired by user is valid
	vector<int> guessCodeVec; // the vector of user input 
	char continueDecision;
	bool gameContinue = false;
	
	//cout << "Enter number of digits in code (3, 4 or 5): ";
	//cin >> numVals;
	while(!gameContinue)
	{
		while(!valid) {
			cout << "Enter number of digits in code (0, 3, 4, or 5): ";
			cin >> numVals;
			if(numVals == 0 || numVals == 3 || numVals == 4 || numVals == 5)
				valid = true;
			else
				cout << "ERROR: VALUE MUST BE 0, 3, 4, OR 5" << endl << endl;
		}
		
		if(numVals != 0)
			game345(numVals);
		else
			gameZero();
		cout << "Do you want to play again? (Enter 'y' or 'n'): ";
		cin >> continueDecision;
		
		if(continueDecision == 'n')
		{
			cout << endl << "Exiting" << endl;
			return 0;
		}

	}
}
