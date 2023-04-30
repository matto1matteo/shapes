#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

#include <SFML/Graphics.hpp>

#include <game/game.h>
#include <shapes/rectangle.h>
#include <shapes/circle.h>

Game Game::FromConfigFile(std::string config_file)
{
    std::fstream stream(config_file);
    return Game::FromStream(stream);
}

Game Game::FromStream(std::istream & input)
{
    Game window;
    std::string resource_type;

    std::string shape_name;
    int posX = 0, posY = 0;
    float speedX = 0.0, speedY = 0.0;
    int radius = 0, width = 0, heigth = 0;
    int red = 0, green = 0, blue = 0;

    // Window
    input >> resource_type;
    if (resource_type != "Window")
        throw "Something bad happened";
    input >> window.m_Width;
    input >> window.m_Height;

    // Font
    input >> resource_type;
    if (resource_type != "Font")
        throw "Something bad happened";
    input >> window.m_Font;

    // Shapes
    while ((input >> resource_type) && !(input.eof() || input.bad() || input.fail()))
    {
        input >> shape_name;
        // Position
        input >> posX;
        input >> posY;

        // Speed
        input >> std::setprecision(10) >> speedX;
        input >> std::setprecision(10) >> speedY;

        // Colors
        input >> red;
        input >> green;
        input >> blue;

        if (resource_type == "Circle") {
            input >> radius;
            Circle * c = new Circle(shape_name, speedX, speedY, posX, posY, radius); 
            c->SetColor(red, green, blue);
            window.m_Shapes.push_back(c);
        }

        if (resource_type == "Rectangle") {
            input >> width;
            input >> heigth;
            Rectangle * r = new Rectangle(shape_name, speedX, speedY, posX, posY, width, heigth);
            r->SetColor(red, green, blue);
            window.m_Shapes.push_back(r);
        }
    }

    return window;
}

int Game::MainLoop()
{
    sf::RenderWindow w (sf::VideoMode(m_Width, m_Height), "Test 1");
    w.setSize(sf::Vector2u(m_Width, m_Height));
    w.setFramerateLimit(60);

    while (w.isOpen())
    {
        sf::Event event;
        while(w.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                std::cout << "Closing SFML Window" << std::endl;
                w.close();
            }
        }

        w.clear();
        for (auto shape : m_Shapes)
        {
            BoundBox b = { 0, 0, m_Width, m_Height };
            shape->MoveShape(b);
            sf::Shape * sfml_shape = shape->GetSFMLShape();
            auto color = shape->GetSFMLColor();
            sfml_shape->setFillColor(color);
            w.draw(*sfml_shape);
        }
        w.display();
        
    }

    return 0;
}

#ifdef BUILD_TEST
#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <iostream>
TEST_CASE("FromStream", "[GetConfigFromStram]")
{
    std::stringstream stream;
    stream << "Window 100 200\n";
    stream << "Font fonts/tech.ttf\n";
    stream << "Circle ACircle 1.0 1.0 100 100 255 255 255 5\n";
    Game w;
    SECTION("Test Window width and heigth")
    {
        stream.seekg(0);
        w = Game::FromStream(stream);
        REQUIRE(w.GetHeigth() == 200);
        REQUIRE(w.GetWidth() == 100);
    };

    SECTION("Test Window font")
    {
        stream.seekg(0);
        w = Game::FromStream(stream);
        REQUIRE(w.GetFont() == "fonts/tech.ttf");
    };

    SECTION("Main Loop")
    {

    };
}
#endif // DEBUG
