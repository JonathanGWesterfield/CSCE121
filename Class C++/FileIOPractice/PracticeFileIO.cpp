#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string getCensorWord(string badWord) {
	// create substitution that is same
	//   length as badWord
	string censorWord;
	for (int i = 0; i < badWord.size(); ++i) {
		int which = rand() % 9; // 9 possible characters
		switch (which) {
		case 0:
			censorWord += '!';
			break;
		case 1:
			censorWord += '@';
			break;
		case 2:
			censorWord += '#';
			break;
		case 3:
			censorWord += '$';
			break;
		case 4:
			censorWord += '%';
			break;
		case 5:
			censorWord += '&';
			break;
		case 6:
			censorWord += '*';
			break;
		case 7:
			censorWord += '?';
			break;
		case 8:
			censorWord += '^';
			break;
		}
	}
	return censorWord;
}

int main(){//int argc, char* argv[]) {
	
	/*string progName;
	if(argc <= 1)
	{
		cerr << "Usage: " << argv[0] << "  inputfile censorfile[outputfile]" << endl;
		return 1;
	}
	progName = argv[0];
	string inFilename = argv[1];
	string censorFilename = argv[2];
	string outFilename = "censored.txt";
	if(argc >= 4)
	{
		outFilename = argv[3];
	}*/
	
	// Get filenames - For now we will hard code the names
	string censorWordsFilename = "censorwords.txt";
	string originalTextFilename = "original.txt";
	string censoredTextFilename = "censored.txt";

	// Declare/Define/Open filestreams
	ifstream censorIn;
	ifstream originalIn;
	ofstream censoredOut;
	
	censorIn.open(censorWordsFilename);
	originalIn.open(originalTextFilename);
	censoredOut.open(censoredTextFilename);

	// make sure all files were opened and give feedback if not
	if (!censorIn.is_open()) {
		cerr << "Failed to open censor word file: " << censorWordsFilename << endl;
		return 1;
	}

	if (!originalIn.is_open()) {
		cerr << "Failed to open censor word file: " << originalTextFilename << endl;
		return 1;
	}

	if (!censoredOut.is_open()) {
		cerr << "Failed to open censor word file: " << censoredTextFilename << endl;
		return 1;
	}

	// get list of words to censor from file
	vector<string> censorWords; // = { "coffee", "java", "bean" };
	string word;
	while (censorIn >> word) { // update and termination condition
		if (word.size() > 0) {
			for (int i = 0; i < word.size(); ++i) {
				word.at(i) = tolower(word.at(i));
			}
			censorWords.push_back(word);
		}
	}

	// print out list of censored words (for debugging) remove later from final program
	cout << "Words to Censor: " << endl;
	for (unsigned int i = 0; i < censorWords.size(); ++i) {
		cout << censorWords.at(i) << endl;
	}
	cout << endl;

	// read original, process and send to output
	// process line by line
	while (!originalIn.eof()) {
		string line, originalLine;
		// get next line
		getline(originalIn, line);
		originalLine = line;

		// convert to all lower case
		for (int i = 0; i < line.size(); ++i) {
			line.at(i) = tolower(line.at(i));
		}

		// see if each censor word is in line
		for (int i = 0; i < censorWords.size(); ++i) {
			string censorWord = censorWords.at(i);
			int location = line.find(censorWord);
			while (location != string::npos) { 
			// while there is a censor word to replace
				line.replace(location, censorWord.size(), getCensorWord(censorWord));
				originalLine.replace(location, censorWord.size(), getCensorWord(censorWord));
				location = line.find(censorWord);
			}
		}
		// if it is there, replace with symbols
		// output modified line
		censoredOut << originalLine << endl;
	}

	// following so I can see the output
	//cout << endl;
	//system("pause");
}