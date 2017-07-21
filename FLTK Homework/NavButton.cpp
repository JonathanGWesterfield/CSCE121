#include <iostream>
#include "NavButton.h"
#include "Viewer.h"
#include <cstring>
using namespace std;

NavButton::NavButton(string imageFilename, string label, int x, int y, int thumbnailsize, int imageIndex, const char *L) :
        Fl_Button(x, y, 1, 1, L), clickCount(0), label(label), thumbnailsize(thumbnailsize), imageLabel(nullptr) {
    setImage(imageFilename);
}

string NavButton::getLabel() const {
    return label;
}

//int NavButton::totalClicks = 0;

void NavButton::setImage(string filename) {
    delete imageLabel;
    imageLabel = new Fl_JPEG_Image(filename.c_str());
    imageLabel->copy(thumbnailsize, thumbnailsize);
    image(imageLabel);
    this->resize(this->x(), this->y(), thumbnailsize + Viewer::borderSize, thumbnailsize + Viewer::borderSize);
}

int NavButton::handle(int event)
{
	// static int numTotalCalled = 0;
  if(this->label == "Previous Button")
  {
    switch(event)
    {
      case FL_RELEASE:
        cout << "Previous button has been pressed " << ++numPrevCalled << " times." << endl;
        cout << "All buttons have been pressed " << ++totalClicks << " times." << endl;
			do_callback();
        return 1;
      default:
        return Fl_Widget::handle(event);
    }
  }
  if(this->label == "Next Button")
  {
    switch(event)
    {
      case FL_RELEASE:
        cout << "Next button has been pressed " << ++numNextCalled << " times." << endl;
        cout << "All buttons have been pressed " << ++totalClicks << " times." << endl;
			do_callback();
        return 1;
      default:
        return Fl_Widget::handle(event);
    }
  }
}

int NavButton::totalClicks = 0;

