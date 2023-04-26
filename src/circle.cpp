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

void Circle::MoveShape(BoundBox & b)
{
    // Check for bound box
    // case for a clam utility function
    SetPosX(GetPosX() + GetSpeedX());
    if ((GetPosX() + (2 * m_Radius)) >= b.X)
    {
        SetPosX(b.X - (2 * m_Radius));
        SetSpeedX(-GetSpeedX());
    }
    else if (GetPosX() <= b.ZeroX)
    {
        SetPosX(b.ZeroX);
        SetSpeedX(-GetSpeedX());
    }

    SetPosY(GetPosY() + GetSpeedY());
    if (GetPosY() >= b.Y)
    {
        SetPosY(b.Y - (2 * m_Radius));
        SetSpeedY(-GetSpeedY());
    }
    else if (GetPosY() <= b.ZeroY)
    {
        SetPosY(b.ZeroY);
        SetSpeedY(-GetSpeedY());
    }
    auto cur_position = m_Shape.getPosition();
    cur_position.x += GetSpeedX();
    cur_position.y += GetSpeedY();
    m_Shape.setPosition(cur_position);
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

