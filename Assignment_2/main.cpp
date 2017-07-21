/*
Student Name: Jonathan Westerfield 
Student UIN: 224005649		
Lab Work # 8
*/

#include <iostream>
using namespace std;
int main()
{
	char grade;
    cout << "Please enter a character grade (A, B, C, D, or F): ";
    cin >> grade;

    switch (grade)
    {
		
        case 'A': cout << "Great work. " << endl;
				 break;
           
		case 'B': cout << "Good work. " << endl;
				 break;

        case 'C': cout << "Passing work. " << endl;
                break;
        case 'D': cout << "Poor work. " << endl;
                cout << "See your instructor." << endl;
                break;
        case 'F': cout << "Unsatisfactory work. " << endl;
                cout << "See your instructor." << endl;
                break;
		default: cout << grade << " is not a legal grade. " << endl;
         // Add a default case that prints
         //     grade " is not a legal grade."
    } 	
   return 0;
}
    