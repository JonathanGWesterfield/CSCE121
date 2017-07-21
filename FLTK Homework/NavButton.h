//
// Created by Jonathan G. Westerfield on 11/28/16.
//

#ifndef NAVBUTTON_H
#define NAVBUTTON_H

#include <string>
#include <FL/Fl.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Button.H>
//#include "Viewer.h"


class NavButton : public Fl_Button {
    std::string label;
    Fl_JPEG_Image* imageLabel;
    int clickCount;
    static int totalClicks;

    int thumbnailsize;
    int numNextCalled = 0;
    int numPrevCalled = 0;


public:
    NavButton(std::string imageFilename, std::string label,
              int x, int y, int thumbnailsize, int imageIndex = 0,
			  const char *L = 0);

    std::string getLabel() const;
    void setImage(std::string);
    int handle(int event);

};

#endif //IMAGE_VIEWER_NAVBUTTON_H