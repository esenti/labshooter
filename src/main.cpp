#include <SFML/Graphics.hpp>
#include "Level.h"
#include "SoundManager.h"
#include <vector>
#include <iostream>

void move(float x, float y, sf::Sprite& sprite, sf::Sprite obstacle)
{
    sprite.move(x, y);

    if(sprite.getGlobalBounds().intersects(obstacle.getGlobalBounds()))
    {
        sprite.move(-x, -y);
    }
}
Level level;

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game window", sf::Style::Default, settings);

    sf::Clock clock;

    sf::Texture playerTexture;
    playerTexture.loadFromFile("assets/player.png");

    sf::Texture tileTexture;
    tileTexture.loadFromFile("assets/tile.png");

    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);

    sf::Sprite tileSprite;
    tileSprite.setTexture(tileTexture);

    SoundManager::LoadSound("shoot", "assets/shoot.wav");
    SoundManager::LoadSound("hurt", "assets/hurt.wav");

    level.LoadLevel("assets/level1");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        level.Update(elapsed.asMilliseconds());
        /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            move(0.5 * elapsed.asMilliseconds(), 0, playerSprite, tileSprite);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            move(-0.5 * elapsed.asMilliseconds(), 0, playerSprite, tileSprite);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            move(0, -0.5 * elapsed.asMilliseconds(), playerSprite, tileSprite);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            move(0, 0.5 * elapsed.asMilliseconds(), playerSprite, tileSprite);
        }*/

        tileSprite.setPosition(50, 50);

        // clear the window with black color
        window.clear(sf::Color::White);

        // draw everything here...
        //window.draw(playerSprite);
        //window.draw(tileSprite);
        level.Render(&window);

        // end the current frame
        window.display();
    }

    return 0;
}
