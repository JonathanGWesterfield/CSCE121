#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "input coefficients a, b & c separated by spaces: ";
	double a;
	double b;
	double c;
	cin >> a >> b >> c;
	
	if(a == 0) {
		cout <<"Not a quadratic equation." << endl;
	}
	else {
		double discriminant = (b*b) - (4 * a * c);
		if(discriminant < 0) {
			cout << "No real roots." << endl;
		}
		else {
			double root1 = (-b + sqrt(discriminant)) / (2 * a);
			double root2 = (-b - sqrt(discriminant)) / (2 * a);
			cout << "x = " << root1 << endl;
			cout << "x = " << root2 << endl;
		}
	}
	
	return 0;
}