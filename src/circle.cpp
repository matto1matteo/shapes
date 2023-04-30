#include <shapes/shapes.h>
#include <iostream>
#include <shapes/circle.h>
#include <sstream>

Circle::Circle(std::string name, float speedX, float speedY, int posX, int posY, int radius)
    : Shape(name, posX, posY, speedX, speedY)
    , m_Radius(radius)
    , m_Shape(radius)
{
    m_Shape.setPosition(GetPosX(), GetPosY());
    m_Shape.setFillColor(GetSFMLColor());
}

void Circle::Print() const
{
    std::cout << ToString() << std::endl;
}

sf::Shape * Circle::GetSFMLShape()
{
    return &m_Shape;
}

void Circle::MoveShape(const BoundBox & b)
{
    float posX = GetPosX();
    float posY = GetPosY();
    float speedX = GetSpeedX();
    float speedY = GetSpeedY();
    float diameter = m_Radius * 2;

    // Check for bound box
    // case for a clam utility function
    SetPosX(posX + speedX);
    if ((GetPosX() + diameter) >= b.X)
    {
        SetPosX(b.X - diameter);
        SetSpeedX(-speedX);
    }
    else if (GetPosX() <= b.ZeroX)
    {
        SetPosX(b.ZeroX);
        SetSpeedX(-speedX);
    }

    SetPosY(posY + speedY);
    if (GetPosY() + diameter >= b.Y)
    {
        SetPosY(b.Y - diameter);
        SetSpeedY(-speedY);
    }
    else if (GetPosY() <= b.ZeroY)
    {
        SetPosY(b.ZeroY);
        SetSpeedY(-speedY);
    }

    sf::Vector2f position = sf::Vector2f(GetPosX(), GetPosY());
    m_Shape.setPosition(position);
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

