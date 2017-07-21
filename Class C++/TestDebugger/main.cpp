// Plays the game of craps.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDice();		// function prototype

// Simulate rolling two dice.  We need a separate call
// to rand() for each die roll to get the same distribution
// as rolling two actual dice.
int rollDice()
{
	return (rand() % 6 + rand() % 6 + 2);
}

int main()
{
  int wallet = 1000;
  bool gameOver = false;
  srand((unsigned int)time(NULL)); // Seed the random number generator

  while (!gameOver)
  {
	cout << "Enter amount to bet. You have $" << wallet << endl;
	int bet;
	cin >> bet;
	if (bet < 0)
		cout << "Bet must be positive." << endl;
	else if (bet > wallet)
		cout << "You don't have that much money." << endl;
	else
	{
		// Make initial roll
		int roll = rollDice();
		cout << "You rolled " << roll << endl;
		// Check for a win or loss or the point
		switch (roll)
		{
			case 7:
			case 11:
				cout << "You win!" << endl;
				wallet += bet;
				break;
			case 2:
			case 3:
			case 12:
				cout << "You lose." << endl;
				wallet -= bet;
				break;
			default:
				// Continue rolling until we roll the point
				// or 7
				int point = roll;
				cout << "The point is " << point << endl;
				do
				{
					roll = rollDice();
					cout << "You rolled " << roll << endl;
					if (roll == 7)
					{
					  cout << "You lose." << endl;
				 	  wallet -= bet;
					}
					else if (roll == point)
					{
					  cout << "That matches the point!" <<
						" You win!" << endl;
					  wallet += bet;
					}
				} while ((roll != 7) && (roll != point));
		}
	}
	if (wallet == 0)
	{
		cout << "You are penniless. Thanks for playing." << endl;
		gameOver = true;
	}
	else
	{
		cout << "Play again? (y/n)" << endl;
		char c;
		cin >> c;
		if (c=='n')
			gameOver = true;
	}
    cout << "You ended the game with $" << wallet << endl;
  }

}        