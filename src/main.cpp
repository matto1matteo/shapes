#include "shapes/rectangle.h"
#include <iostream>
#include <ostream>
#include <shapes/shapes.h>
#include <shapes/circle.h>
#include <window/window.h>

int main (int argc, char *argv[])
{
    Window w = Window::FromConfigFile("./config.txt");
    Circle c = Circle("ACircle", 1.0, -0.1, 10, 10, 5);
    Rectangle r;
    std::cout << Greet("Matteo") << std::endl;
    c.Print();
    r.Print();

    std::cout << "\n\n";
    std::cout << w.GetWidth() << " x " << w.GetHeigth() << std::endl;
    return 0;
}

