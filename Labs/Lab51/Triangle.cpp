//
// Created by Jonathan G. Westerfield on 11/22/16.
//

#include "Triangle.h"
#include <FL/fl_draw.H>
#include <iostream>
using namespace std;

Triangle::Triangle()
{
    p1 = Point(0,0);
    p2 = Point(0,0);
    p3 = Point(0,0);
}
Triangle::Triangle(Point p1, Point p2, Point p3, Color c) : Shape(p1,c)
{
    this -> p1 = p1;
    this -> p2 = p2;
    this -> p3 = p3;
}

void Triangle::draw()
{
    fl_color(linecolor);
    fl_line(p1.x, p1.y, p2.x, p2.y);
    fl_line(p2.x, p2.y, p3.x, p3.y);
    fl_line(p3.x, p3.y, p1.x, p1.y);
}
void Triangle::print_parameters()
{
    cout << "Triangle object." << endl;
    cout << "Vertex 1: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "Vertex 2: (" << p2.x << ", " << p2.y << ")" << endl;
    cout << "Vertex 3: (" << p3.x << ", " << p3.y << ")" << endl;
    cout << "Color: " << linecolor << endl;
}