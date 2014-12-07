//
//  Player.cpp
//  labshooter
//
//  Created by Pawel Miniszewski on 07.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#include "Player.h"


Player::Player(int i) : Entity()
{
    index = i;
}

Player::~Player()
{

}

void Player::Update(float dt)
{
    sf::Vector2f dir;
    if(sf::Keyboard::isKeyPressed((index == 0) ? sf::Keyboard::D : sf::Keyboard::Right))
    {
        dir.x += 1;
    }
    if(sf::Keyboard::isKeyPressed((index == 0) ? sf::Keyboard::A : sf::Keyboard::Left))
    {
        dir.x += -1;
     }
     if(sf::Keyboard::isKeyPressed((index == 0) ? sf::Keyboard::W : sf::Keyboard::Up))
     {
         dir.y += -1;
     }
     if(sf::Keyboard::isKeyPressed((index == 0) ? sf::Keyboard::S : sf::Keyboard::Down))
     {
         dir.y += 1;
     }
    dir.x *= 0.5 * dt;
    dir.y *= 0.5 * dt;

    Move(dir);
}
