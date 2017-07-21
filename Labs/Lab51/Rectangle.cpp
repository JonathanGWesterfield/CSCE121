/*
    Rectangle class derived from Shape class
*/
// #include <Windows.H>    // REQUIRED FOR WINDOWS ONLY
#include <iostream>
#include <FL/fl_draw.H>
#include "Rectangle.h"

using namespace std;

Rect::Rect(unsigned int w, unsigned int h, Point p, Color c)
        : Shape(p, c), width(w), height(h) {}

void Rect::set_width(unsigned int w) {
    this->width = w;
}

unsigned int Rect::get_width() const {
    return this->width;
}

void Rect::set_height(unsigned int h) {
    this->height = h;
}

unsigned int Rect::get_height() const {
    return this->height;
}

void Rect::draw() {
    fl_color(linecolor);
    fl_rect(position.x, position.y, width, height);
}

void Rect::print_parameters() {
    cout << "Rectangle object.\n\t"
         << "Width: " << width << ", Height: " << height
         << ", Position: (" << position.x << ", " << position.y << "), Color: " << linecolor << ".\n";
}