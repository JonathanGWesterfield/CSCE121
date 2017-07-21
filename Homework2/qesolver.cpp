#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>

using namespace std;

// FIX ME: put a case if there can be no valid solutions
int main()
{
	float varA; //creates the variables for each coefficient
	float varB;
	float varC;
	double root1; //creates the variables for the roots
	double root2;
	double discriminant; //variable to determine if has real roots
	
	cout << fixed;
	cout.precision(5);
	cout << "Enter the coefficients of your equation : "; 
	cin >> varA;
	cin >> varB; //takes in variables for coefficients
	cin >> varC;
	
	cout << endl << "Your equation : " << varA << "x^2 + "; //prints full equation
	cout << varB << "x + " << varC << " = 0" << endl;
	
	if(varA == 0) //determines if there is division by zero
	{
		root1 = (0 - varC) / varB; // means equation is linear and solves for x
		cout << "Equation is linear." << endl; 
		cout << "x = " << root1 << endl;
	}
	
	else
	{
		discriminant = pow(varB, 2.0) - (4 * varA * varC); 
		
		if(discriminant < 0) //determines if roots are imaginary
		{
			double rootpt1; //splits roots into 2 parts 
			double rootpt2;
			
			rootpt1 = -varB / (2 * varA); //solves for both parts of the roots
			rootpt2 = sqrt( abs(discriminant)) / (2 * varA);
			cout << "x = " << rootpt1 << " - " << rootpt2 << "i" << endl; //prints imaginary roots
			cout << "x = " << rootpt1 << " + " << rootpt2 << "i" << endl;
		}
		
		else //has real roots
		{
			root1 = (-varB - sqrt(discriminant)) / (2 * varA); //solves for real roots
			root2 = (-varB + sqrt(discriminant)) / (2 * varA);
			cout << "x = " << root1 << endl; //prints real roots
			cout << "x = " << root2 << endl;
		}
	}
	
	return 0;
	
}