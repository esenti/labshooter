//
//  Player.cpp
//  labshooter
//
//  Created by Pawel Miniszewski on 07.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#include "Player.h"


Player::Player() : Entity()
{
    
}

Player::~Player()
{
    
}

void Player::Update(float dt)
{
    sf::Vector2f dir;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dir.x += 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dir.x += -1;
     }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
     {
         dir.y += -1;
     }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
     {
         dir.y += 1;
     }
    dir.x *= 0.5 * dt;
    dir.y *= 0.5 * dt;
    
    Move(dir);
}