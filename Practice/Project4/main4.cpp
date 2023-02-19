/*
* myid: [43824]
* Those are the last five digits
* Author: <kevin.diazgochez@baruchmail.cuny.edu>
* Kevin Diaz Gochez
* Assignent due 3/15/2020
*/

#include<iostream>
using namespace std;


int main() {

	int count = 0;
	int count_2 = 0;
	int count_3 = 0;

	for (int i = 1; i <= 5000000; i++) {
		if (((i % 13 == 0)) && ((i % 2 == 0)))
			count++;

		else if (((i % 17 == 0)) && ((i % 2 == 0)))
			count_2++;

		else if (((i % 19 == 0)) && ((i % 2 == 0)))
			count_3++;
	}

int total = count + count_2 + count_3;
cout << total << endl;


	return 0;
}
