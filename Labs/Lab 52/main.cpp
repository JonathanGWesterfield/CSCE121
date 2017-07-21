#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_GIF_Image.H>
#include <FL/Fl_Box.H>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    srand(time(NULL)); // set random seed based on current time
    vector<string> filenames {"cloudy.gif","fog.gif","lightning.gif","partsunny.gif","rain.gif","sunny.gif"};

    string filename = filenames.at(rand() % filenames.size()); // get randome filename
    //cout << "Image File: " << filename << endl; // for debugging

    Fl_Window *window = new Fl_Window(300, 180);
    window->begin();
    Fl_Button *button = new Fl_Button(150,90,80,60);
    //Fl_GIF_Image *myImage;
    //myImage = new Fl_GIF_Image("rain.gif");

    //button->image(myImage);
    Fl_Box *box = new Fl_Box(20, 40, 260, 100, "Hello, World!");
    box->box(FL_UP_BOX);
    box->labelfont(FL_HELVETICA_BOLD_ITALIC);
    box->labelsize(36);
    box->labeltype(FL_SHADOW_LABEL);
    window->end();
    window->show(argc, argv);
    return Fl::run();

    // Start add code for image on button

    //cout << img.w() << "X" << img.h() << endl; // for debugging

    // End code for image on button
}










