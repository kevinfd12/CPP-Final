 /* 
* myid: [43824] 
* Those are the last five digits
* Author: <kevin.diazgochez@baruchmail.cuny.edu>
* Kevin Diaz Gochez
* Assignent due 3/5/2020 
*/


#include<iostream>
using namespace std;

int main() {

	int count = 0;

	// count of the numbers between 0 and 40 that are divisible by 11, 13, 17, 19

	for (int i = 0; i < 5000000; i++) {
		if ((i % 11 == 0) || (i % 13 == 0) || (i % 17 == 0) || (i % 19 == 0)) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}

