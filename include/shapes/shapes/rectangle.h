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
    Rectangle(std::string name, float speedX, float speedY, int posX, int posY, int width, int height)
        : Shape(name, speedX, speedY, posX, posY)
        , m_Width(width), m_Height(height)
    {}

    std::string ToString() const override;

private:
    int m_Width;
    int m_Height;
};


inline Rectangle::Rectangle()
    : Shape(), m_Width(0), m_Height(0)
{}
