#pragma once
#include <string>

std::string Greet(std::string s);

class Shape
{
public:
    Shape() = default;
    Shape(Shape &&) = default;
    Shape(const Shape &) = default;
    Shape &operator=(Shape &&) = default;
    Shape &operator=(const Shape &) = default;
    ~Shape() = default;

    Shape(std::string name, int posX, int posY, float speedX, float speedY)
        : m_Name(name) , m_PosX(posX), m_PosY(posY) , m_SpeedX(speedX), m_SpeedY(speedY)
    {}

    void Print() const;
    virtual std::string ToString() const = 0;

    const int GetPosX() const { return m_PosX; };
    const int GetPosY() const { return m_PosY; };
    const int GetSpeedX() const { return m_SpeedX; };
    const int GetSpeedY() const { return m_SpeedY; };
    const std::string GetName() const { return m_Name; };

private:
    std::string m_Name;
    int m_PosX;
    int m_PosY;
    float m_SpeedX;
    float m_SpeedY;

};
