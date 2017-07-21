#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <ctime>
#include <math.h>
#include <algorithm>
using namespace std;

/* Function declarations */
// PLACE median_by_val declaration after this line

float median_by_val(vector<int> v);



/* Globals */
const long NUM_VALUES = 100000; // ADJUST THIS

/*
    Main Function
    Do NOT modify this function unless you are asked to do so.
*/
int main() {
    const int RANGE = 10000;
    srand(1);

    cout << "value of NUM_VALUES: " << NUM_VALUES << endl;
    vector<int> values;
    for (long i = 0; i < NUM_VALUES; i++) {
        int val = rand() % RANGE;
        values.push_back(val);
    }
    cout << "size of vector<int> values: " << values.size() << endl;

    

     // UNCOMMENT LINE BELOW ONCE ADDED FUNCTION
    float medianV = median_by_val(values);
	cout << endl << medianV <<endl;

     /* end median-by-value routine */
}

/*
    Function definitions.
    ALL function definitions should be contained after this line.
    Your functions must not include any cout statements.
*/

// PLACE median_by_val definition after this line
float median_by_val(vector<int> v)
{
	sort(v.begin(), v.end());
	float med;
	if (v.size() % 2 == 0) 
	{
		int a = (v.size() - 1) / 2;
		int b = a + 1;
		med = ((v[a] + v[b]) / 2);
	}
	else 
	{
		med = v[(v.size() - 1) / 2];
	}
	return med;
}
