#pragma once
#include <string>

#include <SFML/Graphics.hpp>

#include <shapes/bound_box.h>

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

    const float GetPosX() const { return m_PosX; }
    void SetPosX(float posX) { m_PosX = posX; }
    const float GetPosY() const { return m_PosY; }
    void SetPosY(float posY) { m_PosY = posY; }
    const float GetSpeedX() const { return m_SpeedX; }
    void SetSpeedX(int speedX) { m_SpeedX = speedX; }
    const float GetSpeedY() const { return m_SpeedY; }
    void SetSpeedY(float speedY) { m_SpeedY = speedY; }
    const std::string GetName() const { return m_Name; }
    void SetColor(std::uint8_t red, std::uint8_t green, std::uint8_t blue);
    sf::Color GetSFMLColor() const;

    virtual sf::Shape * GetSFMLShape() = 0;
    virtual void MoveShape(const BoundBox & b) = 0;

private:
    std::string m_Name;
    float m_PosX;
    float m_PosY;
    float m_SpeedX;
    float m_SpeedY;

    std::uint8_t m_Red;
    std::uint8_t m_Green;
    std::uint8_t m_Blue;

};
