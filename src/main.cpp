#include "shapes/rectangle.h"
#include <iostream>
#include <ostream>
#include <shapes/shapes.h>
#include <shapes/circle.h>
#include <window/window.h>

int main (int argc, char *argv[])
{
    Window w = Window::FromConfigFile("./config.txt");
    std::cout << w.GetWidth() << " x " << w.GetHeigth() << std::endl;
    return 0;
}

