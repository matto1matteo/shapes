#include "shapes/rectangle.h"
#include <iostream>
#include <shapes/shapes.h>
#include <shapes/circle.h>

int main (int argc, char *argv[])
{
    Circle c = Circle("ACircle", 1.0, -0.1, 10, 10, 5);
    Rectangle r;
    std::cout << Greet("Matteo") << std::endl;
    c.Print();
    r.Print();
    return 0;
}
