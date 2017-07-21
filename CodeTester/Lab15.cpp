#include <iostream>
#include <limits>
using namespace std;

int main()
{

    int value;

    cout << "Enter an integer (or 0 to exit): ";
    cin >> value;

    while(!cin.good()) {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears the buffer

	cout << "Invalid input, enter number again" << endl;
	cin >> value;
    }

    cout << "You entered: " << value << endl << endl;

    /* STEP1: Test the code as-is with the following inputs
          654321
          -1234
          asdf
              .987
    */

    /* STEP2A: Embed the above code into a while loop that repeatedly asks the user for input until a valid value is
     * input. See video for an example.
    */

    /* STEP2B: Test with the values suggested below.
    */

    /* STEP3A: Add cin.clear(); after determining that there was an error
    */

    /* STEP3B: Test with the values suggested below.
    */

    /* STEP4A: Replace cin.clear() with cin.ignore(numeric_limits<streamsize>::max(), '\n');
    */

    /* STEP4B: Test with the values suggested below.
    */

    /* STEP5A: Add both cin.clear() and cin.ignore(numeric_limits<streamsize>::max(), '\n');
    */

    /* STEP5B: Test with the values suggested below.
    */

    /*
            Test values
            654321
            -1234
            asdf
            asdf123
            123asdf
            asdf 123
            123 asdf
            123.456
            123 456
            0.987
            .987
            987654321
            9876543210
    */
}