#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "config.h"

class Game
{
private:
    int width;
    int height;
    std::string title;
    sf::RenderWindow window;
    std::string source_dir;

    sf::Texture backgroundTexture;
    sf::Sprite background;

    int x;
    int y;
    float dy;

    sf::Texture playerModelRight;
    sf::Texture playerModelLeft;
    sf::IntRect playerRect;
    sf::Sprite player;

    void Tick();
    void Move();

public:
    Game();
    ~Game();

    void run();
};
