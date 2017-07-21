#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include "functions.h"

using namespace std;

void printusageinfo(int argc, vector<string> cmdParam)
{
	string programName;
	{
		if(argc < 2)
		programName = cmdParam.at(0);
		cerr << "Usage: " << programName << endl;
		cerr << "./palindrome [-c] [-s] string ..." << endl;
		cerr << "-c: case sensitivity turned on" << endl;
		cerr << "-s: ignoring spaces turned off" << endl;
	}
	/*
	if(cmdParam.at(0) == "-c" || cmdParam.at(0)  == "-C")
	{
		cout << "case sensitivity turned on" << endl;
	}
	else if(cmdParam.at(0) == "-s" || cmdParam.at(0) == "-S")
	{
		cout << "ignoring spaces turned off" << endl;
	}

	if(cmdParam.at(1)  == "-c" || cmdParam.at(1) == "-C")
	{
		cout << "case sensitivity turned on" << endl;
	}
	else if(cmdParam.at(1) == "-s" || cmdParam.at(1) == "-S")
	{
		cout << "ignoring spaces turned off" << endl;
	}
	
	if((cmdParam.at(1) == "-c" || cmdParam.at(1) == "-C") && (cmdParam.at(1) == cmdParam.at(1)))
	{
		cerr << "Cannot have 2 of the same flags" << endl;
	}
	else if((cmdParam.at(1) == "-c" || cmdParam.at(1) == "-C") && cmdParam.at(1) == cmdParam.at(1))
	{
		cerr <<  "Cannot have 2 of the same flags" << endl;
	}*/
}

int isflag(int argcount, const vector<string> &argumentsPass, bool& Case, bool& Space)
{
	string firstFlag = argumentsPass[0];
	cout << "The First inputted flag: " << firstFlag << endl;
	//firstFlag = tolower(firstFlag);
	string secondFlag = argumentsPass[1];
	transform(firstFlag.begin(), firstFlag.end(), firstFlag.begin(), ::tolower);
	cout << "The First inputted flag: " << firstFlag << endl;
	if(argumentsPass[0] == "-cs"||argumentsPass[0] == "-sc")
	{
		cout << "flag: " << firstFlag << endl;
	}
	return 0;
}
int main(int argc, char* argv[])
{
	bool treatCase = false;
	bool ignoreSpace = false;
	cout << "Argument list : " << argv[0] << endl;
	for(int i = 0; i < argc; i++)
	{
		cout << "Argument " << i << ": " << argv[i] << endl;
	}
	vector<string> arguments;
	for(int i = 1; i < argc; i++)
	{
		arguments.push_back(argv[i]);
		cout << "args list size: " << arguments.size();
	}
	cout << "args list size: " << arguments.size();
	printusageinfo(argc, arguments);
	isflag(argc, arguments, treatCase, ignoreSpace);
}


