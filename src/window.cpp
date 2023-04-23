#include "shapes/circle.h"
#include "shapes/rectangle.h"
#include <fstream>
#include <string>
#include <window/window.h>

Window Window::FromConfigFile(std::string config_file)
{
    Window window;
    std::fstream stream(config_file);
    std::string resource_type;

    std::string shape_name;
    int posX = 0, posY = 0;
    float speedX = 0.0, speedY = 0.0;
    int radius = 0, width = 0, heigth = 0;
    int red = 0, green = 0, blue = 0;

    // Window
    stream >> resource_type;
    if (resource_type != "Window")
        throw "Something bad happened";
    stream >> window.m_Width;
    stream >> window.m_Height;

    // Font
    stream >> resource_type;
    if (resource_type != "Font")
        throw "Something bad happened";
    stream >> window.m_Font;

    // Shapes
    do {
        stream >> resource_type;
        stream >> shape_name;
        // Speed
        stream >> speedX;
        stream >> speedY;

        // Position
        stream >> posX;
        stream >> posY;

        // Colors
        stream >> red;
        stream >> green;
        stream >> blue;

        if (resource_type == "Circle") {
            stream >> radius;
            window.m_Shapes.push_back(new Circle(shape_name, speedX, speedX, posX, posY, radius));
        }

        if (resource_type == "Rectangle") {
            stream >> width;
            stream >> heigth;
            window.m_Shapes.push_back(new Rectangle(shape_name, speedX, speedY, posX, posY, width, heigth));
        }
    } while (stream.eof() || stream.bad());

    return window;
}
