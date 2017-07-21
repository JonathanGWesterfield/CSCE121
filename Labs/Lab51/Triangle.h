//
// Created by Jonathan G. Westerfield on 11/22/16.
//

#ifndef LAB_51_FLTK_TRIANGLE_H
#define LAB_51_FLTK_TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
private:
    Point p1;
    Point p2;
    Point p3;
public:
    Triangle();
    Triangle(Point p1 = Point(0,0), Point p2 = Point(0,0), Point p3 = Point(0,0), Color c = black);
    void draw();
    void print_parameters();
};

#endif //LAB_51_FLTK_TRIANGLE_H
