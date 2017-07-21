#include <iostream>
#include "Viewer.h"

using namespace std;

void buttonCallback(Fl_Widget* widget, void* viewerPtr) {
    cout << "Callback called" << endl;
    Viewer* viewer = static_cast<Viewer*>(viewerPtr);
    viewer->navPressed(widget);
    /* you can name this whatever you want, the idea is to call a
         member function in the viewer class that does what is needed
         to update the image. You'll pass in the widget (you can also
         dynamic cast it to a NavButton before passing it). From the
         widget the function can determine whether to move forward
         or backward in the list.
    */
	viewer->redraw();
}
void Viewer::navPressed(Fl_Widget* w) {
	if(w == next)
		currentIndex = ((currentIndex + 1) < imageFilenames.size()) ? (currentIndex + 1): 0;
	else
		currentIndex = ((currentIndex - 1) > 0) ? (currentIndex - 1) : (imageFilenames.size() - 1);
	next->setImage(getPathFilename(imageFilenames.at((currentIndex < (imageFilenames.size() - 1)) ? (currentIndex + 1) : 0), true));
	prev->setImage(getPathFilename(imageFilenames.at((currentIndex > 0) ? (currentIndex - 1) : (imageFilenames.size() - 1)), true));
	pic = new Fl_JPEG_Image(getPathFilename(imageFilenames.at(currentIndex)).c_str());
	imageBox->image(pic);
	this->redraw();
}
/*
void Viewer::handle(int event)
{
	switch(event)
	{
		case FL_KEYBOARD:
			return 1;
			break;
		case Fl_LEFT_MOUSE:
			return;
		default:
			return handle_key(event, FL::event_key)
			break;
	}
}

int Viewer::handle_key(int event, int key)
{
	switch (event) {
    case FL_Right:
			next->do_callback();
			return 1;
			break;
		case FL_Left:
			prev->do_callback();
			return 1;
			break;
			
  default:
			return Fl_Widget::handle(event);
			break;
	}
}*/

Viewer::Viewer(string imageFolder, vector<string> imageFilenames, int width = 800, int height = 600) :
        Fl_Window(width, height, "Image Viewer"), imageFolder(imageFolder), imageFilenames(imageFilenames), currentIndex(0),
        prev(nullptr), next(nullptr), imageBox(nullptr), pic(nullptr) {
			void* viewerpointer = (void*) this;
    prev = new NavButton(getPathFilename(imageFilenames.at(imageFilenames.size()-1), true),
                         "Previous Button",
                         borderSize,
                         this->h() - borderSize - thumbnailSize - borderSize,
                         thumbnailSize, imageFilenames.size() - 1);
    next = new NavButton(getPathFilename(imageFilenames.at((imageFilenames.size()+1)%imageFilenames.size()), true),
                         "Next Button",
                         this->w() - borderSize - thumbnailSize - borderSize,
                         this->h() - borderSize - thumbnailSize - borderSize,
                         thumbnailSize, imageFilenames.size()-1);
    imageBox = new Fl_Box(borderSize,
                          borderSize,
                          this->w() - (2*borderSize),
                          this->h() - (2*borderSize) - thumbnailSize - 2*borderSize);
    //imageBox->box(FL_BORDER_BOX); // useful to see where the full size of the widget holding the images

    pic = new Fl_JPEG_Image(getPathFilename(imageFilenames.at(currentIndex)).c_str());
    imageBox->image(pic);
	prev->callback(buttonCallback, static_cast<void*>(this));
	next->callback(buttonCallback, static_cast<void*>(this));
			
    this->end();
}

string Viewer::getPathFilename(string filename, bool thumb) {
    string thumbPart = "";
    if (thumb) thumbPart = "t_";
    return imageFolder + "/" + thumbPart+ filename;
}
