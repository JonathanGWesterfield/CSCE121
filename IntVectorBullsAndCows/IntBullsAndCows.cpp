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

vector<int> randomNumberGenerator(int vectorSize)
{
	vector<int> possibleNums;
	vector<int> Code;
	srand(time(0)); // Seed the random number generator
	for(int i = 0; i < 10; i++)
	{
		possibleNums.push_back(i);
	}
	random_shuffle(possibleNums.begin(), possibleNums.end());
	possibleNums.resize(vectorSize);
	return possibleNums;
}

/* This function is useless because this function is now embedded in 
 * the convertToVector() function*/
vector<int> addBeginningZero(vector<int> guessCode, int numVals)
{
	int numZeros = numVals - guessCode.size();
	cout << "num zeros is" << numZeros << endl;
	reverse(guessCode.begin(), guessCode.end());
	//guessCode.push_back(0);
	
	if(numZeros > 1)
	{
		for(int i = 1; i < numZeros; i++)
		{
			guessCode.push_back(0);
		}
	}
	guessCode.push_back(0);
	reverse(guessCode.begin(), guessCode.end());
	
	// will insert zeros which will make the program output an error
	// in the game345 and gameZero method if more than 1 zero
	
	return guessCode;
}

vector<int> convertToVector(int guess, int numDigits)
{
	int numVals = 0; // number of digits in user's number
	int tempGuess = guess;
	while(tempGuess) // will determine the number of digits in the number
	{
		tempGuess /= 10;
		numVals++;
	}
		
	vector<int> guessCodeVec;
	for(int i = numVals - 1; i >= 0; i--) 
	{
		int indexNum = guess % 10;
		guessCodeVec.push_back(indexNum);
		guess /= 10;
	}
	if(guessCodeVec.size() < numDigits)
	{
		int numZeros = numDigits - numVals;
		for(int i = 0; i < numZeros; i++)
		{
			guessCodeVec.push_back(0);
		}
		
	}
	reverse(guessCodeVec.begin(), guessCodeVec.end());
	
	 //for debugging and confirming output
	/*for(int i = 0; i < guessCodeVec.size(); i++)
	{
		cout << guessCodeVec.at(i);
	}
	cout << endl; //<< guessCodeVec.size() << endl;*/
	 
	return guessCodeVec;
}

void game345(int numVals)
{
	int bulls = 0;
    int cows = 0;
	vector<int> codeVec; //the random generated code
	
	codeVec = randomNumberGenerator(numVals);
	cout << "Number to guess: ";
	for(int i = 0; i < codeVec.size(); i++)
	{
		cout << codeVec.at(i);
	}
	cout << endl;
	
	int guess;
	vector<int> guessCode; //the guess the user inputs
	
	cin.ignore(numeric_limits <streamsize>::max(), '\n'); //clears buffer to allow reading
	while (cout << "Enter guess: ", cin >> guess)
	{
		guessCode = convertToVector(guess, numVals);
		
		//if the guess is smaller than the code add zero(s) in front of the vector
		// because of changes to convertToVector(), this function call is useless
		// This also is the same for gameZero()
		if(guessCode.size() < numVals)
		{
			guessCode = addBeginningZero(guessCode, numVals);// will send to method that adds a leading zero
		}
		else if(guessCode.size() > numVals)
		{
			cout << "Number is too large. Please try again." << endl;
			continue;
		}
		if (contains_duplicate(guessCode))
		{
			/*for(int i = 0; i < guessCode.size(); i++)
			{
				cout << guessCode.at(i);
			}*/
			cout << endl << "Each number must be different. " << endl;
			continue;
		}
		for(int i = 0; i < guessCode.size(); i++)
		{
			if(codeVec.at(i) == guessCode.at(i))
			{
				bulls++;
				cows --;
			}
			for(int j = 0; j < codeVec.size(); j++)
			{
				if(guessCode.at(i) == codeVec.at(j))
				{
					cows++;
				}
			}
		}
		
		if(bulls == codeVec.size())
		{
			
			cout << bulls << " bulls - ";
			for(int i = 0; i < codeVec.size(); i++)
			{
				cout << codeVec.at(i);
			}
			cout << " is Correct!" << endl;
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
	int Code;
	int guess;
	int bulls = 0;
	int cows = 0;
	int numVals;
	bool valid = false;
	vector<int> codeVec; // the code the user inputs to guess
	vector<int> guessCode;//the guess the user inputs
	
	// just submit this to see what vocareum wants
	
	while(!valid)
	{
		cout << "Enter code: ";
		cin >> Code;
	
		cout << "Enter number of digits in code: ";
		cin >> numVals;
		codeVec = convertToVector(Code, numVals);
		
		if (contains_duplicate(codeVec))
		{
			for(int i = 0; i < guessCode.size(); i++)
			{
				cout << guessCode.at(i);
			}
			cout << endl << "Each number must be different. " << endl;
		}
		else
		{
			valid = true;
		}
	}

	
	cout << "Number to guess: ";
	for(int i = 0; i < codeVec.size(); i++)
	{
		cout << codeVec.at(i);
	}
	cout << endl;
	
	
	 
	
	cin.ignore(numeric_limits <streamsize>::max(), '\n'); //clears buffer to allow reading
	while (cout << "Enter guess: ", cin >> guess)
	{
		guessCode = convertToVector(guess, numVals);
		// FIXME : put method for interpreting the number as individual digits
		
		if(guessCode.size() < numVals)
		{
			guessCode = addBeginningZero(guessCode, numVals);// will send to method that adds a leading zero
		}
		else if(guessCode.size() > numVals)
		{
			cout << "Number is too large. Please try again." << endl;
			continue;
		}
		if (contains_duplicate(guessCode))
		{
			for(int i = 0; i < guessCode.size(); i++)
			{
				cout << guessCode.at(i);
			}
			cout << endl << "Each number must be different. " << endl;
			continue;
		}
		for(int i = 0; i < guessCode.size(); i++)
		{
			if(codeVec.at(i) == guessCode.at(i))
			{
				bulls++;
				cows --;
			}
			for(int j = 0; j < codeVec.size(); j++)
			{
				if(guessCode.at(i) == codeVec.at(j))
				{
					cows++;
				}
			}
		}
		
		if(bulls == codeVec.size())
		{
			
			cout << bulls << " bulls - ";
			for(int i = 0; i < codeVec.size(); i++)
			{
				cout << codeVec.at(i);
			}
			cout << " is Correct!" << endl;
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
