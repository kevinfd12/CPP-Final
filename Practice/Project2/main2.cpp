/**
* myid: [43824] 
* Those are the last five digits
* Author: <kevin.diazgochez@baruchmail.cuny.edu>
* Kevin Diaz Gochez
* Assignent due 2/20/2020 
* when I compiled my result was "The result value where k_value >= 1.69 && length < 12 is: 8" 
*/

//I did an else if for the last one to make sure I understand how to use this variation. It was just for practice in real scenario I would be consistent. 
//I was going to put } else { cout << "ERROR: Couldn't determine what to take...did you answer y/n?" << endl; but it would not make sense because this isnt taking user input so it would not need this part. We could control it to always take double. 

#include<iostream>

using namespace std;

//Kevin F <------- Name I am using
int main() {
	double num_consonants = 4;
	double num_vowels = 2;
	double length = num_consonants + num_vowels;
	double k_value = num_consonants / num_vowels;


	cout << k_value << endl;
	cout << length << endl;
	if (k_value < 1.69 && length >= 12) {
		double result = (length * num_consonants);
		cout << "The Result Value where K_value < 1.69 && length >= 12 is: " << result << endl;
	}
	else {
		if (k_value < 1.69 && length < 12) {
			double result = (length * num_vowels);
			cout << "The Result Value where k_value < 1.69 && length < 12 is: " << result << endl;
		}
		else {
			if (k_value >= 1.69 && length >= 12) {
				double result = (length + num_consonants);
				cout << "The result value where k_value >= 1.69 && length >= 12 is: " << result << endl;
			}
			else if ((k_value >= 1.69 && length < 12)) {
				double result = (length + num_vowels);
				cout << "The result value where k_value >= 1.69 && length < 12 is: " << result << endl;
				}
			}

		}
	return 0;
}
