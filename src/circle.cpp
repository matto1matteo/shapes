#include "shapes/shapes.h"
#include <iostream>
#include <shapes/circle.h>
#include <sstream>

Circle::Circle(std::string name, float speedX, float speedY, int posX, int posY, int radius)
    : Shape(name, posX, posY, speedX, speedY), m_Radius(radius)
{
}

void Circle::Print() const
{
    std::cout << ToString() << std::endl;
}

std::string Circle::ToString() const
{
    std::stringstream stream;
    stream << "Name: " << GetName() << "\n";
    stream << "Pos: (" << GetPosX() << ", " << GetPosY() << ")\n";
    stream << "Speed: (" << GetSpeedX() << ", " << GetSpeedY() << ")\n";
    stream << "radius: " << m_Radius << "\n";
    stream << "---------------------------------------------\n";
    return stream.str();
}
