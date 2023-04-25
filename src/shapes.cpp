#include <iostream>
#include <shapes/shapes.h>


std::string Greet(std::string s)
{
    return "Hello " + s + "!";
}

void Shape::Print() const
{
    std::cout << ToString() << std::endl;
}

void Shape::SetColor(std::uint8_t red, std::uint8_t green, std::uint8_t blue)
{
    m_Red = red;
    m_Green = green;
    m_Blue = blue;
}

sf::Color Shape::GetSFMLColor() const
{
    return sf::Color(m_Red, m_Green, m_Blue);
}

#ifdef BUILD_TEST
#include <catch2/catch_test_macros.hpp>
TEST_CASE("Hello Greet simple test", "[Greet]")
{
    REQUIRE(Greet("Matteo") == "Hello Matteo!");
}

#endif // BUILD_TEST
