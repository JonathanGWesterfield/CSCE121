//
// Created by Jonathan G. Westerfield on 10/20/16.
//

#ifndef NEWPALINDROMES_FUNCTIONS_H
#define NEWPALINDROMES_FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;

void printUsageInfo(const string& program_name);
int isflag(int argcount, const vector<string> &argumentsPass, bool& Case, bool& Space);
bool isPalindrome(const string& phrase, bool case_sensitive, bool keep_spaces);
void phraseToLowerCase(string& phrase);
void phraseIgnoreSpace(string& phrase);
void removePunctuation(string& phrase);

#endif //NEWPALINDROMES_FUNCTIONS_H
