#include "Game.hpp"

Game::Game()
{
    width = 320;
    height = 512;
    title = "Doodle Jump";
    window.create(sf::VideoMode(width, height), title);
    window.setFramerateLimit(60);
    source_dir = RESOURCE_PATH;

    backgroundTexture.loadFromFile(source_dir + "background.png");
    background.setTexture(backgroundTexture);

    playerModelRight.loadFromFile(source_dir + "doodle-right.png");
    playerModelRight.setSmooth(true);
    playerModelLeft.loadFromFile(source_dir + "doodle-left.png");
    playerModelLeft.setSmooth(true);
    playerRect.left = 0;
    playerRect.top = 0;
    playerRect.width = 62;
    playerRect.height = 60;
    player.setTexture(playerModelLeft);
    player.setTextureRect(playerRect);
    player.setPosition(width / 2.0 - playerRect.width / 2.0, 0);

    x = player.getPosition().x;
    y = player.getPosition().y;
    dy = 0.0;
}

Game::~Game()
{
}

void Game::Tick()
{
    Move();
    window.draw(background);
    window.draw(player);
}

void Game::Move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player.setTexture(playerModelLeft);
        x -= 3;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player.setTexture(playerModelRight);
        x += 3;
    }

    dy += 0.2;
    y += dy;

    // TMP:
    // Simulate a jump to see if physics works
    if (y > height - playerRect.height)
        dy = -10;

    if (x < 0 - playerRect.width)
        x = width;

    if (x > width)
        x = 0 - playerRect.width;

    player.setPosition(x, y);
}

void Game::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        Tick();

        window.display();
    }
}