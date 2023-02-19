#include<iostream>
using namespace std;

/*
* myid: [43824]
* Those are the last five digits
* Author: <kevin.diazgochez@baruchmail.cuny.edu>
* Kevin Diaz Gochez
* Assignent due 3/15/2020
*/
int count1 = 0;

// The name used in the spreadheet sent at beginning of semester: Kevin F
// Full name: Kevin F Diaz Gochez. Last Name I am using Diaz Gochez

bool endsN(int Num) {
	if (Num % 10 == 1)
		return true;
	else
		return false;
}

bool isPrime(int num) {
	for (int i = 2; i < num; i++)
		if (num % i == 0)
			return false;
			return true;
}

void myFunction(int A, int B) {
	for (int i = A; i < B; i++) {
		if ((isPrime(i)) && (endsN(i)))
			count1++;
	}

	cout << count1 << endl;
}


int main() {

	const int A = (10 * 100); //1000
	const int B = (250 * 16); //4000

	myFunction(A, B);



	return 0;
}
