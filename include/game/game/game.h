#pragma once
#include <istream>
#include <string>
#include <vector>
#include <shapes/shapes.h>
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game() = default;
    Game(Game &&) = default;
    Game(const Game &) = default;
    Game &operator=(Game &&) = default;
    Game &operator=(const Game &) = default;
    ~Game() = default;

    static Game FromConfigFile(std::string config_file);
    static Game FromStream(std::istream & input);

    // Accessors
    const int GetWidth() const { return m_Width; }
    const int GetHeigth() const { return m_Height; }
    void SetFont(std::string font);
    std::string GetFont() const { return m_Font; }

    int MainLoop();

private:
    int m_Width;
    int m_Height;
    std::vector<Shape *> m_Shapes;
    std::string m_Font;
};

