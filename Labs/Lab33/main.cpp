/**
* Main.cpp
*/

#include <iostream>

using namespace std;

class Color {
    /* Public */
public:
    Color() {
        this -> R = 255;
        this -> G = 255;
        this -> B = 255;
    };
    Color(int r, int g, int b)
    {
        this -> R = r;
        this -> G = g;
        this -> B = b;
    };// default constructor

    void cout_rgb (void) { cout << "Color Values: (" << R <<
                                ',' << G << ',' << B << ')' << endl;}
    /* Private */
private:
    int R;
    int G;
    int B;
};

/**
* main()
*/
int main()
{
    Color color;
    color.cout_rgb();
    Color color2(80,0,0);
    color2.cout_rgb();
    int Red, Green, Blue;
    cout << "Please enter integer values for R, G, and B: ";
    cin >> Red >> Green >> Blue;
    Color color3(Red, Green, Blue);
    color3.cout_rgb();
}