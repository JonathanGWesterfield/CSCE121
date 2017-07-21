//
// Created by Jonathan G. Westerfield on 11/22/16.
//

#ifndef LAB_51_FLTK_RECTANGLE_H
#define LAB_51_FLTK_RECTANGLE_H

/*
    Rectangle class derived from Shape class
*/

//#ifndef _RECT_H
//#define _RECT_H

#include "Shape.h"

class Rect : public Shape {
private:
    unsigned int width, height;

public:
    Rect(unsigned int w = 0, unsigned int h = 0, Point p = Point(0, 0), Color c = black);

    void set_width(unsigned int w);
    unsigned int get_width() const;
    void set_height(unsigned int h);
    unsigned int get_height() const;

    void draw();
    void print_parameters();
};

//#endif
#endif //LAB_51_FLTK_RECTANGLE_H
