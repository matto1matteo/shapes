#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include <fstream>
#include <string>
#include <window/window.h>

Window Window::FromConfigFile(std::string config_file)
{
    std::fstream stream(config_file);
    return Window::FromStream(stream);
}

Window Window::FromStream(std::istream & input)
{
    Window window;
    std::string resource_type;

    std::string shape_name;
    int posX = 0, posY = 0;
    float speedX = 0.0, speedY = 0.0;
    int radius = 0, width = 0, heigth = 0;
    int red = 0, green = 0, blue = 0;

    // Window
    input >> resource_type;
    if (resource_type != "Window")
        throw "Something bad happened";
    input >> window.m_Width;
    input >> window.m_Height;

    // Font
    input >> resource_type;
    if (resource_type != "Font")
        throw "Something bad happened";
    input >> window.m_Font;

    // Shapes
    do {
        input >> resource_type;
        input >> shape_name;
        // Speed
        input >> speedX;
        input >> speedY;

        // Position
        input >> posX;
        input >> posY;

        // Colors
        input >> red;
        input >> green;
        input >> blue;

        if (resource_type == "Circle") {
            input >> radius;
            window.m_Shapes.push_back(new Circle(shape_name, speedX, speedX, posX, posY, radius));
        }

        if (resource_type == "Rectangle") {
            input >> width;
            input >> heigth;
            window.m_Shapes.push_back(new Rectangle(shape_name, speedX, speedY, posX, posY, width, heigth));
        }
    } while (input.eof() || input.bad());

    return window;
}
