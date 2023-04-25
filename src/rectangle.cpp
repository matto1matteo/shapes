#include <shapes/rectangle.h>
#include <sstream>

Rectangle::Rectangle(std::string name, float speedX, float speedY, int posX, int posY, int width, int height)
    : Shape(name, posX, posY, speedX, speedY)
    , m_Width(width), m_Height(height)
    , m_Shape(sf::Vector2f(width, height))
{
    m_Shape.setPosition(GetPosX(), GetPosY());
    m_Shape.setFillColor(GetSFMLColor());
}

std::string Rectangle::ToString() const
{
    std::stringstream stream;
    stream << "Name: " << GetName() << "\n";
    stream << "Pos: (" << GetPosX() << ", " << GetPosY() << ")\n";
    stream << "Speed: (" << GetSpeedX() << ", " << GetSpeedY() << ")\n";
    stream << "Size: (" << m_Width << " x " << m_Height << ")\n";
    stream << "---------------------------------------------\n";
    return stream.str();
    return "";
}

sf::Shape * Rectangle::GetSFMLShape()
{
    return &m_Shape;
}
