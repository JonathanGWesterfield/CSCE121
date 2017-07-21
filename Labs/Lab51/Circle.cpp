/*
    Circle class derived from Shape class
*/

// #include <Windows.H>    // REQUIRED FOR WINDOWS ONLY
#include <iostream>
#include <FL/fl_draw.H>
#include "Circle.h"

using namespace std;

Circle::Circle(unsigned int r, Point p, Color c)
        : Shape(p, c), radius(r) {}

void Circle::set_radius(unsigned int r) {
    this->radius = r;
}

unsigned int Circle::get_radius() const {
    return this->radius;
}

void Circle::draw() {
    fl_color(linecolor);
    fl_arc(position.x, position.y, 2 * radius, 2 * radius, 0, 360);
}

void Circle::print_parameters() {
    cout << "Circle object.\n\t"
         << "Radius: " << radius
         << ", Position: (" << position.x << ", " << position.y << "), Color: " << linecolor << ".\n";
}
