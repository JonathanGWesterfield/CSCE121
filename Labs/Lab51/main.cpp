// #include <Windows.H>    // REQUIRED FOR WINDOWS ONLY
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <vector>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

int main(int argc, char **argv) {
    Fl_Window *window = new Fl_Window(800, 600);

    Rect r1(400, 165, Point(50, 245), blue);
    Circle c1(200, Point(300, 180), red);
    Triangle t1(Point(200, 200), Point(200,600), Point(600,300), yellow);
    Triangle t2(Point(70, 300), Point(400,500), Point(100,100), magenta);

    vector<Shape*> shapes;
    shapes.push_back(&r1);
    shapes.push_back(&c1);
    shapes.push_back(&t1);
    shapes.push_back(&t2);
    for (unsigned int i = 0; i < shapes.size(); i++)
        shapes.at(i)->print_parameters();

    window->end();
    window->show(argc, argv);
    return Fl::run();
}
