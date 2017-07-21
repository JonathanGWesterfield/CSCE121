#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <ctime>
#include <math.h>
using namespace std;

/* Function declarations */
void print_vector_contents (vector<int> &v);

/* Globals */
const long NUM_VALUES = 100;

/*
    Main Function
    Do NOT modify this function unless you are asked to do so.
*/
int main() {
    const int RANGE = 10000;
    srand(1);

    vector<int> values;
    for (long i = 0; i < NUM_VALUES; i++) {
        int val = rand() % RANGE;
        values.push_back(val);
    }
    cout << "size of vector<int> values: " << values.size() << endl;

    print_vector_contents(values);
    sort(values.begin(), values.end());
    print_vector_contents(values);
    print_vector_contents(values);

}

/*
    Function definitions.
    ALL function definitions should be contained after this line.
*/
// PLACE print_vector_contents code after this line
void print_vector_contents (vector<int> &v) {
	int temp;
    for(int i = 0; i < v.size(); i++)
	{
		//cout << v.at(i) << endl;
		temp = v.at(i);
		v.at(i) = v.at(v.size()-1-i);
		v.at(v.size() - 1-i) = temp;
		cout << v.at(i) << endl;
	}
	
}


