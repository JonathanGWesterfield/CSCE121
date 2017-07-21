#include <iostream>

using namespace std;

int main()
{
	string firstName;
	string lastName;
	int birthYear;
	int heightFeet;
	int heightInches;
	int age;
	double heightCentimeters;
	double averageGrowth;
	
	cout << "Enter first name : ";
	cin >> firstName;
	cout << "Enter last name : ";
	cin >> lastName;
	cout << "Enter birth year : ";
	cin >> birthYear;
	cout << "Enter height in feet : ";
	cin >> heightFeet;
	cout << "Enter height in inches : ";
	cin >> heightInches;
	cout << endl;
	
	age = 2016 - birthYear;
	heightCentimeters = (heightFeet * 12) * 2.54 + (heightInches * 2.54);
	averageGrowth = (heightCentimeters - 51) / age;
	
	cout << "Hello " << firstName << " " << lastName << ". " << endl;
	cout << "Your were " << age << " years old in 2016, and your height is " << heightCentimeters << " cm. " << endl;
	cout << "That means that you grew an average of " << averageGrowth << " cm per year (assuming you were 51 cm at birth)." << endl;
	return 0;
}