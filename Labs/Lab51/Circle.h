
#ifndef LAB_51_FLTK_CIRCLE_H
#define LAB_51_FLTK_CIRCLE_H
/*
    Circle class derived from Shape class
*/
//#ifndef _CIRC_H
//#define _CIRC_H

#include "Shape.h"

class Circle : public Shape {
private:
    unsigned int radius;

public:
    Circle(unsigned int r = 0, Point p = Point(0,0), Color c = black);

    void set_radius(unsigned int r);
    unsigned int get_radius() const;

    void draw();
    void print_parameters();
};

//#endif
#endif //LAB_51_FLTK_CIRCLE_H
