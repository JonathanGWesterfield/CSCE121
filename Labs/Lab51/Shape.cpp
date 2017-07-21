/*
    Base Shape class from which other shape classes can be derived, and
    Color enum and Point struct for descriptive shape object feautures.
*/
// #include <Windows.H>    // REQUIRED FOR WINDOWS ONLY
#include <FL/Fl.H>
#include "Shape.h"


Point::Point(int x, int y)
        : x(x), y(y) { }


Shape::Shape(Point p, Color c)
        : Fl_Widget(p.x, p.y, 0, 0), position(p), linecolor(c) { }

void Shape::set_color(Color c) {
    this->linecolor = c;
}

Color Shape::get_color() const {
    return this->linecolor;
}

void Shape::set_position(Point p) {
    this->position = p;
}

Point Shape::get_position() const {
    return this->position;
}