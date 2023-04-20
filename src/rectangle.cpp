#include <shapes/rectangle.h>
#include <sstream>

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
