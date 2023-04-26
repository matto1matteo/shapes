#pragma once

#include <string>
#include "shapes.h"

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle(Rectangle &&) = default;
    Rectangle(const Rectangle &) = default;
    Rectangle &operator=(Rectangle &&) = default;
    Rectangle &operator=(const Rectangle &) = default;
    ~Rectangle() = default;
    Rectangle(std::string name, float speedX, float speedY, int posX, int posY, int width, int height);

    std::string ToString() const override;
    sf::Shape * GetSFMLShape() override;
    void MoveShape(BoundBox & b) override;

private:
    int m_Width;
    int m_Height;

    sf::RectangleShape m_Shape;
};


inline Rectangle::Rectangle()
    : Shape(), m_Width(0), m_Height(0)
{}
