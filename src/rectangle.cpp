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

void Rectangle::MoveShape(BoundBox & b)
{
    // Check for bound box
    // case for a clam utility function
    SetPosX(GetPosX() + GetSpeedX());
    if ((GetPosX() + (2 * m_Width)) >= b.X)
    {
        SetPosX(b.X - (2 * m_Width));
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
        SetPosY(b.Y - (2 * m_Height));
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

sf::Shape * Rectangle::GetSFMLShape()
{
    return &m_Shape;
}
