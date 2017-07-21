#include "functions.h"

int main(int argc, char* argv[])
{
    bool treatCase = false;
    bool ignoreSpace = true;
    bool palindromeConfirm = false;
    string argFirstIndex = argv[0];
    vector<string> originalArguments;
    int numFlagIndexRemoval = 0;
    string word;

    if(argc == 1)
    {
        word = argv[0];
        printUsageInfo(word);
        exit(0);
    }

        //cout << "Argument list : " << argv[0] << endl;

        /*for(int i = 0; i < argc; i++)
        {
            cout << "Argument " << i << ": " << argv[i] << endl;
        }*/

        vector<string> arguments;
        for(int i = 1; i < argc; i++)
        {
            arguments.push_back(argv[i]);
        }
        //cout << "args list size: " << arg3uments.size() << endl;

        numFlagIndexRemoval = isflag(arguments.size(), arguments, treatCase, ignoreSpace);

        if((argc - numFlagIndexRemoval) ==1)
        {
            word = argv[0];
            printUsageInfo(word);
            exit(0);

        }

        for(int i = 0; i < numFlagIndexRemoval; i++)
        {
            arguments.erase(arguments.begin());
        }

        /*for(int i = 0; i < arguments.size(); i++)
        {
            cout << "Arguments after erasure: " << arguments.at(i) << endl;
        }*/

        originalArguments = arguments;

        /*for(int i = 0; i < arguments.size(); i++)
        {
            removePunctuation(arguments.at(i));
            cout << "Arguments after Puncuation erasure: " << arguments.at(i) << endl;
        }*/

        if(ignoreSpace == true)
        {
            for(int i = 0; i < arguments.size(); i++)
            {
                phraseIgnoreSpace(arguments.at(i));
            }
        }
        for(int i = 0; i < arguments.size(); i++)
        {
            if(treatCase == false)
            {
                phraseToLowerCase(arguments.at(i));
            }
        }
        /*for(int i = 0; i < arguments.size(); i++)
        {
            cout << "Final Arguments before Palindrome Analysis: " << arguments.at(i) << endl;
        }*/

        for(int i = 0; i < arguments.size(); i++)
        {
            palindromeConfirm = isPalindrome(arguments.at(i), treatCase, ignoreSpace);
            if(palindromeConfirm == true)
            {
                cout << "\""<< originalArguments.at(i) << "\" is a palindrome." << endl;
            }
            else if(palindromeConfirm ==  false)
            {
                cout << "\""<< originalArguments.at(i) << "\" is not a palindrome." << endl;
            }

        }


}


