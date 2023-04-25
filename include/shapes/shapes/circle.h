#pragma once
#include <string>
#include "shapes.h"

class Circle : public Shape
{
public:
    Circle();
    Circle(std::string name, float speedX, float speedY, int posX, int posY, int radius);
    Circle(Circle &&) = default;
    Circle(const Circle &) = default;
    Circle &operator=(Circle &&) = default;
    Circle &operator=(const Circle &) = default;
    ~Circle();

    void Print() const;
    std::string ToString() const override;

    sf::Shape * GetSFMLShape() override;

private:
    int m_Radius;
    sf::CircleShape m_Shape;
};

inline Circle::Circle()
    : Shape(), m_Radius(0)
{
}

inline Circle::~Circle()
{
}
