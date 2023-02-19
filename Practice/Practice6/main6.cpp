
/*
* myid: [43824]
* Those are the last five digits
* Author: <kevin.diazgochez@baruchmail.cuny.edu>
* Kevin Diaz Gochez
* Assignent due 4/30/2020
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAX_NAMES = 6000; // maximum num of names we will work with



// function opens a text file with its name mentioned in the
// parameter textFileName, then reads all the names
// inside that file (which should have 1 name per line)
// into the array called names[]. At the end, the
// function returns how many actual names were read from
// the file, and the names[] array is populated with
// all the names read from the file. Additionally,
// at most MAX_NAMES number of names will be read from the
// file
int readNamesFromFile(string names[], string textFileName) {

	int numOfNames = 0;

	ifstream inputFile;
	inputFile.open(textFileName);

	if (!inputFile) {
		// could not open the file
		cout << "Error: not able to open file (check path!):"
			<< textFileName << endl;
	}
	else {
		// was able to open the file
		// in a while loop, keep reading names from the file
		// and keep track of the array index (as well as name count)
		// while reading, make sure we are not exceeding MAX_NAMES
		string name;
		int i = 0;
		while (inputFile >> name && (numOfNames < MAX_NAMES)) {
			names[i] = name;
			i++;
			numOfNames++;
		}
		inputFile.close();
	}


	return numOfNames;

}

// function that prints the first n items
// of a string array called stringArray

void printFirstN(string stringArray[], int numElements, int n) {

	// start at 0th index (first element)
	// end at nth element
	int startIndex = 0;
	int stopIndex = n;
	for (int i = startIndex; i < stopIndex; i++) {
		// formatting out put to look like:
		// 0: name0
		// 1: name1
		// ...
		// n: namen
		cout << i << ":" << stringArray[i] << endl;
	}
}



// function that prints the last n items
// of a string array called stringArray
// note: in order to print last n, we need to know
// how many elements there actually are in this
// array and loop the index backwards
void printLastN(string stringArray[], int numElements, int n) {
	// starts at the last element
	int startIndex = numElements - 1;
	// end n elements before start element
	int stopIndex = startIndex - n;

	// looping backward from last element to laste element - n
	for (int i = startIndex; i > stopIndex; i--) {
		// formatting out put to look like:
		// n: namen
		// n-1: name(n-1)
		// ...

		cout << i << ":" << stringArray[i] << endl;
	}
}



// function that prints all elements of the string
// array that start with "D"
void printNamesStartingWithA(string stringArray[], int numElements) {

	// go through entire array beginning to end
	int countMatchingNames = 0;
	for (int i = 0; i < numElements; i++) {
		string stringElement = stringArray[i];
		// note how stringElement[0]
		// behaves like an array and indexing
		// 0th element provides the 0th character
		// i.e. the first letter
		if (stringElement[0] == 'D') {
			countMatchingNames++;
			cout << stringElement << endl;
		}
	}
	cout << countMatchingNames << " matches the conditions" << endl;
}


// function that prints all elements of the string
// array that ends with "D"
void printNamesEndingWithA(string stringArray[], int numElements) {

	// go through entire array elements beginning to end
	int countMatchingNames = 0;
	for (int i = 0; i < numElements; i++) {
		string stringElement = stringArray[i];
		// note how we get the last index using length
		int lastLetterIndex = stringElement.length() - 1;
		if (stringElement[lastLetterIndex] == 'D') {
			countMatchingNames++;
			cout << stringElement << endl;
		}
	}
	cout << countMatchingNames << " matches the conditions" << endl;
}

/*
void printNameContainsD(string stringArray[], int numElements) {
// go through entire array beginning to end
int countMatchingNames = 0;
for (int i = 0; i < numElements; i++) {
string stringElement = stringArray[i];
int lastLetterIndex = stringElement.length() - 1;
for (int i = 0; i < lastLetterIndex; i++) {
if (stringElement[i] == 'D') {
countMatchingNames++;
cout << "This is the name: " << stringElement << "This is the letter: " << stringElement[i] << endl;
cout << countMatchingNames << endl;
break;
}
}
}
cout << countMatchingNames << " The following matches the conditions where it contains D" << endl;
}
*/

void printNameContainsD(string stringArray[], int numElements) {

	// go through entire array beginning to end
	int countMatchingNames = 0;
	for (int i = 0; i < numElements; i++) {
		string stringElement = stringArray[i];
		int lastLetterIndex = stringElement.length() - 1;
		for (int i = 0; i < stringElement.length(); i++) {
			if (stringElement[i] == 'D') {
				countMatchingNames++;
				break;
			}
		}
	}
	cout << countMatchingNames << endl;
}

int main() {

	string namesArray[MAX_NAMES]; // can hold up to MAX_NAMES names
	string fileName = "C:\\Users\\kevin diaz\\Desktop\\CIS 3100\\names.txt"; // name of the file
	// you may need to fix above filepath depending on where you
	// have the file. Here are possible scenarios:
	// Suppose you have your Username as Jane and file is in desktop
	// Mac: /Users/Jane/Desktop/names.txt
	// Win: C:\\Users\\Jane\\Desktop\\names.txt


	int nameCount; // keeps count of number of names read from file

	// call the readNamesFromFile function
	// get all the names in namesArray and get count of names read
	nameCount = readNamesFromFile(namesArray, fileName);
	//cout << "number of names read from file:" << nameCount << endl;

	/*
	// just a simple test: print the first 20 elements
	cout << "print first 20 names" << endl;
	printFirstN(namesArray, nameCount, 20);
	// just a simple test: print the last 20 elements
	cout << "print last 20 names" << endl;
	printLastN(namesArray, nameCount, 20);
	// another test: print names that start with "A"
	cout << "print names that start with A" << endl;
	printNamesStartingWithA(namesArray, nameCount);
	// another test: print names that ends with "A"
	cout << "print names that end with A" << endl;
	printNamesEndingWithA(namesArray, nameCount);
	*/

	//Whether the name contains D
	printNameContainsD(namesArray, nameCount);


	return 0;
}
