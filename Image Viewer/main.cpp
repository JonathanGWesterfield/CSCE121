#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Viewer.h"

using namespace std;

vector<string> loadFilenames(string imageFolderName, string imageFileListName) {
    vector<string> filenames;
    ifstream is(imageFolderName + "/" + imageFileListName);
    if (!is.is_open()) {
        cerr << "Failed to open " << imageFileListName << endl;
        exit(0);
    }
    cout << "Opened File: " << imageFileListName << endl;

    while (!is.eof()) {
        string filename;
        is >> filename;
        if (filename.size() > 0)
            filenames.push_back(filename);
    }
    return filenames;
}

int main(int argc, char **argv) {
    if (argc <= 2) {
        string progName = argv[0];
        cout << "Usage: " << progName << " imageFolderName imageListFile" << endl;
        return 1;
    }
    string imagefilename = argv[2];
    string imagefolder = argv[1];

    vector<string> filenames = loadFilenames(imagefolder, imagefilename);

    cout << "Setting up Viewer" << endl;

    Viewer* viewer = new Viewer(imagefolder, filenames, 800, 600);

    cout << "Showing Window" << endl;

    viewer->show();

    cout << "Starting Event Loop" << endl;
    return Fl::run();
}