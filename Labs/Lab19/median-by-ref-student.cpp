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
float median_by_ref(vector<int>& v);

/* Globals */
const long NUM_VALUES = numeric_limits<int>::max()*.005; // ADJUST THIS

/*
    Main Function
    Do NOT modify this function unless you are asked to do so.
*/
int main() {
    const int RANGE = 10000;
    srand(1);
    clock_t start;
    double duration;

    cout << "value of NUM_VALUES: " << NUM_VALUES << endl;
    vector<int> values;
    for (long i = 0; i < NUM_VALUES; i++) {
        int val = rand() % RANGE;
        values.push_back(val);
    }
    cout << "size of vector<int> values: " << values.size() << endl;

    /*
        please uncomment this median-by-value routine block if your version median_by_value function was incorrectly written.
    // start median-by-value routine
    start = clock();
    float medianV = median_by_val(values);
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout << "pass by val" << "\tduration: " << duration << " seconds\tmedian:" << medianV << '\n';
    // end median-by-value routine
    */

    // print the first 100 elements of the values vector


    // UNCOMMENT LINE BELOW ONCE ADDED FUNCTION
    float medianR = median_by_ref(values);

 
    // end median-by-reference routine

    // print the first 100 elements of the values vector


}

float median_by_ref(vector<int>& v)
{
	sort(v.begin(), v.end());
	float med;
	if (v.size() % 2 == 0) {
		int a = floor((v.size()-1) / 2);
		int b = a + 1;
		med = ((v[a] + v[b]) / 2);
	}
	else { 
		med = v[(v.size()-1)/2];
	}
	return med;
	}
/*
    Function definitions.
    ALL function definitions should be contained after this line.
    Your functions must not include any cout statements.
*/
// PLACE median_by_ref code after this line

