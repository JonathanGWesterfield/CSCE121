//
// Created by Jonathan G. Westerfield on 10/20/16.
//
#include "functions.h"

void printUsageInfo(const string& program_name)
{
    string programName;
    {
        cout << "Usage: " << program_name << " [-c] [-s] string ..." << endl;
        cout << "-c: case sensitivity turned on" << endl;
        cout << "-s: ignoring spaces turned off" << endl;
    }
}

int isflag(int argcount, const vector<string> &argumentsPass, bool& Case, bool& Space)
{
    string firstFlag;
    string secondFlag;
    int numFlagIndexes = 0;
    if(argumentsPass[0].find('-') != string::npos)
    {
        firstFlag = argumentsPass[0];
        transform(firstFlag.begin(), firstFlag.end(), firstFlag.begin(), ::tolower);
    }

    if(argcount > 1)
    {
        if(argumentsPass[1].find('-') != string::npos)
        {
            secondFlag = argumentsPass[1];
            transform(secondFlag.begin(), secondFlag.end(), secondFlag.begin(), ::tolower);

            if(secondFlag.find('-') != string::npos && (secondFlag.find('s') != string::npos))
            {
                //cout << "Ignoring spaces turned off" << endl;
                Space = false;
                numFlagIndexes += 1;
            }
            else if(secondFlag.find('-') != string::npos && (secondFlag.find('c') != string::npos))
            {
                //cout << "case sensitivity turned on" << endl;
                Case = true;
                numFlagIndexes+= 1;
            }
        }
    }
    if(((firstFlag.find('-') != string::npos) && (firstFlag.find('c') != string::npos)) &&
       ((firstFlag.find('-')) != string::npos) && (firstFlag.find('s') != string::npos))
    {
        //cout << "case sensitivity turned on" << endl;
        Case = true;
        //cout << "Ignoring spaces turned off" << endl;
        Space = false;
        numFlagIndexes += 1;
    }
    else if((firstFlag.find('-') != string::npos) && (firstFlag.find('s') != string::npos))
    {
        //cout << "Ignoring spaces turned off" << endl;
        Space = false;
        numFlagIndexes += 1;
    }
    else if((firstFlag.find('-') != string::npos) && (firstFlag.find('c') != string::npos))
    {
        //cout << "case sensitivity turned on" << endl;
        Case = true;
        numFlagIndexes+= 1;
    }

    /*cout << "Number of flags Indexes: " << numFlagIndexes << endl;
    cout << "Flags: " << firstFlag << ", " << secondFlag << endl;*/
    return numFlagIndexes;
}

void phraseToLowerCase(string& phrase)
{
    transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
    /*for(int i = 0; i < phrase.size(); i++)
    {
        cout << "Phrase to lower case functions: " << phrase.at(i) << endl;
    }*/
}

void removePunctuation(string& phrase)
{
    for(int j = 0; j < phrase.size(); j++)
    {
        for(int i = 0; i < phrase.size(); i++)
        {
            if((phrase.at(i) == '!') || (phrase.at(i) == '?') || (phrase.at(i) == '.') ||
                    (phrase.at(i) == ';') || (phrase.at(i) == ':'))
            {
                phrase.erase(phrase.begin() + i);
            }
        }
        /*for(int i = 0; i < phrase.size(); i++)
        {
            cout << "Phrase Remove punctuation functions: " << phrase.at(i) << endl;
        }*/
    }
}

void phraseIgnoreSpace(string& phrase)
{
    for(int j = 0; j < phrase.size(); j++)
    {
        for(int i = 0; i < phrase.size(); i++)
        {
            if(!isalnum(phrase.at(i)))
            {
                phrase.erase(phrase.begin() + i);
            }
        }
        /*for(int i = 0; i < phrase.size(); i++)
        {
            cout << "Phrase ignore spaces functions: " << phrase.at(i) << endl;
        }*/
    }
}

bool isPalindrome(const string& phrase, bool case_sensitive, bool keep_spaces)
{
    string word = phrase;
    int length = word.length();

    string first = word.substr(0,1);
    string last = word.substr((length - 1), 1);
    if (first == last)
    {
        word = word.substr((0 + 1), (length - 2));
        //cout << word << " " << word.length() << endl;  // DEBUGGING
        if (word.length() <= 1) return true;  // Problem line?
        return isPalindrome(word, case_sensitive, keep_spaces);
    }
    else
        return false;
    /*string s = phrase;
    bool palindrome;
    int length = s.length();
    if(length <= 1)
    {
        cout << "Palindrome" << endl;
        palindrome = true;
    }//check for zero or one digit numbers
    else if(s.at(0) == s.at(length -1))
    {
        s = s.substr(1, (length - 2));
        isPalindrome(s, case_sensitive, keep_spaces);
    }
    else
    {
        cout << "Not a palindrome." << endl;
        palindrome = false;
    }*/
}

