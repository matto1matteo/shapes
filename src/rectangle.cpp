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

void Rectangle::MoveShape(const BoundBox & b)
{
    float posX = GetPosX();
    float posY = GetPosY();
    float speedX = GetSpeedX();
    float speedY = GetSpeedY();

    // Check for bound box
    SetPosX(posX + speedX);
    if (( GetPosX() + m_Width) >= b.X)
    {
        SetPosX(b.X - m_Width);
        SetSpeedX(-speedX);
    }
    else if (GetPosX() <= b.ZeroX)
    {
        SetPosX(b.ZeroX);
        SetSpeedX(-speedX);
    }

    SetPosY(posY + speedY);
    if ((GetPosY() + m_Height) >= b.Y)
    {
        SetPosY(b.Y - m_Height);
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

sf::Shape * Rectangle::GetSFMLShape()
{
    return &m_Shape;
}
