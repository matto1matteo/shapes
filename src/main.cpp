#include <iostream>
#include <ostream>
#include <SFML/Graphics.hpp>

#include <shapes/rectangle.h>
#include <shapes/shapes.h>
#include <shapes/circle.h>
#include <game/game.h>

int main (int argc, char *argv[])
{
    Game game = Game::FromConfigFile("/home/mattomatteo/Projects/shapes/config.txt");
    return game.MainLoop();
}

