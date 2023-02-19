/*
myid: [43824]
	* Those are the last five digits
	* Author : <kevin.diazgochez@baruchmail.cuny.edu>
	* Kevin Diaz Gochez
	*/

#pragma comment(linker, "/STACK:5000000")
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const char MYLETTER = 'd'; // change this to first letter of your last name
const int MAXDIGIT = 8;    // change this to max digit of your student id



const int MAX_WORDS = 128739;  // do not change this; max words in file



// function opens a text file with its name mentioned in the
// parameter textFileName, then reads all the words
// inside that file (which should have 1 word per line)
// into the array called words[]. At the end, the
// function returns how many actual words were read from
// the file, and the words[] array is populated with
// all the words read from the file. Additionally,
// at most MAX_WORDS number of words will be read from the
// file
int readWordsFromFile(string words[], string textFileName) {

	int countWords = 0;

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
		string word;
		int i = 0;
		while (inputFile >> word && (countWords < MAX_WORDS)) {
			words[i] = word;
			i++;
			countWords++;
		}
		inputFile.close();
	}


	return countWords;

}

/*
bool scrabbleWord(string myArray[], int wordCount) {
}
*/

/*
void addOne(char x) {
	char myArray[] = { 'e', 'a', 'i', 'o', 'n', 'r', 't', 'l', 's', 'u' };
	for (int i = 0; i < 10; i++) {
		cout << "the value of i " << myArray[i] << endl;
		cout << "the value of x " << x << endl;
		if (x == myArray[i]) {
			cout << "add one" << endl;
			break;
		}
		else {
			cout << "Dont add one" << endl;
		}
	}
}
*/

/*
void addOne(char x) {
	char myArray[] = { 'e', 'a', 'i', 'o', 'n', 'r', 't', 'l', 's', 'u' };
	for (int i = 0; i < 10; i++) {
		if (x == myArray[i]) {
			cout << "The function was true and the x is" << x << "And the i is: " << myArray[i] << endl;
			cout << "This should be true" << endl;
			break;
		}
		else if (x != myArray[i]) {
			cout << "The function was true and the x is" << x << "And the i is: " << myArray[i] << endl;
		}
	}
}
*/

bool addOne(char x) {
		if (x == 'e' || x == 'a' || x == 'i' || x == 'o' || x == 'n' || x == 'r' || x == 't' || x == 'l' || x == 's' || x == 'u') {
			return true;
		}
		else {
			return false;
		}
}

bool addTwo(char x) {
	if (x == 'd' || x == 'g') {
		return true;
	}
	else {
		return false;
	}
}

bool addThree(char x) {
	if (x == 'b' || x == 'c' || x == 'm' || x == 'p') {
		return true;
	}
	else {
		return false;
	}
}

bool addFour(char x) {
	if (x == 'f' || x == 'h' || x == 'v' || x == 'w' || x == 'y') {
		return true;
	}
	else {
		return false;
	}
}

bool addFive(char x) {
	if (x == 'k') {
		return true;
	}
	else {
		return false;
	}
}

bool addEight(char x) {
	if (x == 'j' || x == 'x') {
		return true;
	}
	else {
		return false;
	}
}

bool addTen(char x) {
	if (x == 'q' || x == 'z') {
		return true;
	}
	else {
		return false;
	}
}

int countNumberD(string myArray[], int wordCount) {
	int counter = 0;
	for (int i = 0; i < wordCount; i++) {
		string stringElement = myArray[i];
		int lastLetterIndex = stringElement.length() - 1;
		for (int i = 0; i < stringElement.length(); i++) {
			if (stringElement[i] == MYLETTER) {
				counter++;
				break;
			}
		}

	}
	return counter;
}

bool countNumberD2(string stringElement) {
	for (int i = 0; i < stringElement.length(); i++) {
		if (stringElement[i] == MYLETTER) {
			return true;
			break;
		}

	}

}


int countNumberDonce(string myArray[], int wordCount) {
	int counter = 0;
	for (int i = 0; i < wordCount; i++) {
		int counter2 = 0;
		string stringElement = myArray[i];
		int lastLetterIndex = stringElement.length() - 1;
		for (int i = 0; i < stringElement.length(); i++) {
			if (stringElement[i] == MYLETTER) {
				counter2++;
			}

		}
		if (counter2 == 1) {
			counter++;
		}

	}

	return counter;
}




int scrabbleWords(string stringElement) {
	int result = 0;
	int strPrev = 0;
	for (int i = 0; i < stringElement.length(); i++) {
		result = 0;
			char x = stringElement[i];
			if (addFive(x)) {
					result = 5;
				}
				else if (addOne(x)) {
					result = 1;
				}
				else if (addTwo(x)) {
					result = 2;
				}
				else if (addThree(x)) {
					result = 3;
				}
				else if (addFour(x)) {
					result = 4;
				}
				else if (addEight(x)) {
					result = 8;
				}
				else if (addTen(x)) {
					result = 10;
				}
				else {
					result = 0;
				}
			strPrev = strPrev + result;
		}
		
		return strPrev;
}

int mainWords(string myArray[], int wordCount) {
	int result = 0;
	int strPrev = 0;
	for (int i = 0; i < wordCount; i++) {
		string stringElement = myArray[i];
		if (scrabbleWords(stringElement) > MAXDIGIT && countNumberD2(stringElement) == true) {
			result = scrabbleWords(stringElement);
			//cout << "The word is: " << stringElement << "The number is " << scrabbleWords(stringElement) << "and the value for whether it contains one d is " << countNumberDonce2(stringElement) << endl;
		}

		else {
			//cout << "The word is: " << stringElement << "The number is " << scrabbleWords(stringElement) << "and the value for whether it contains one d is " << countNumberDonce2(stringElement) << endl;
			result = 0;
		}
		strPrev = strPrev + result;
		
	}
	return strPrev;
}

/*void scrabbleWords(string myArray[], int wordCount) {
	int result = 0;
	for (int i = 0; i < wordCount; i++) {
		string stringElement = myArray[i];
		int lastLetterIndex = stringElement.length() - 1;
		int strPrev = 0;
		for (int i = 0; i < stringElement.length(); i++) {
			result = 0;
			char x = stringElement[i];
			if (addFive(x)) {
			result = 5;
			}
			else if (addOne(x)) {
				result = 1;
			}
			else if (addTwo(x)) {
				result = 2;
			}
			else if (addThree(x)) {
				result = 3;
			}
			else if (addFour(x)) {
				result = 4;
			}
			else if (addEight(x)) {
				result = 8;
			}
			else if (addTen(x)) {
				result = 10;
			}
			else {
				result = 0;
			}
			cout << "The value of x" << x << "The value of result" << result << endl;
			strPrev = strPrev + result;
			cout << "This is strPrev" << strPrev << endl;
		}
		cout << "------------------------------------------The value of result is: " << strPrev << endl;
	}
}
*/





int main() {

	string wordsArray[MAX_WORDS]; // can hold up to MAX_WORDS words
	string fileName = "C:\\Users\\kevin diaz\\Desktop\\CIS 3100\\only_english_words.txt"; // name of the file
	// you may need to fix above filepath depending on where you
	// have the file. Here are possible scenarios:
	// Suppose you have your Username as Jane and file is in desktop
	// Mac: /Users/Jane/Desktop/names.txt
	// Win: C:\\Users\\Jane\\Desktop\\names.txt

	int wordCount; // keeps count of number of words read from file

	// call the readWordsFromFile function
	// get all the words in wordsArray and get count of words read
	wordCount = readWordsFromFile(wordsArray, fileName);



	// count of words that contains MYLETTER 1 or more times.
	int answer1 = countNumberD(wordsArray, wordCount);

	// count of words that contains MYLETTER only once.
	int answer2 = countNumberDonce(wordsArray, wordCount);

	
	int answer3 = mainWords(wordsArray, wordCount);
	// sum of scrabble scores of all words such that the word:
	// contains MYLETTER and the word has a scrabble score > MAXDIGIT

	// write code to figure out answers 1-3


	// print the answers
	cout << answer1 << endl;
	cout << answer2 << endl;
	cout << answer3 << endl;

	return 0;
}
