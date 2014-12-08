//
//  Player.cpp
//  labshooter
//
//  Created by Pawel Miniszewski on 07.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#include "Player.h"

#include "Level.h"
#include "Bullet.h"
#include "ResourceCache.h"


Player::Player(int i) : Entity(), index(i), toBullet(500), rotationRate(0.5f), maxSpeed(.5)
{
}

Player::~Player()
{

}

void Player::Update(float dt)
{
    sf::Transform tr;
    tr.rotate(GetRotation());
    bool inputChanged = false;
    sf::Vector2f dir(0,0);
    float rotAngle = 0;

    if(sf::Keyboard::isKeyPressed((index == 0) ? sf::Keyboard::D : sf::Keyboard::Right))
    {
        //dir.x += 1;
        rotAngle = rotationRate;
        inputChanged = true;
    }
    if(sf::Keyboard::isKeyPressed((index == 0) ? sf::Keyboard::A : sf::Keyboard::Left))
    {
        //dir.x += -1;
        tr.rotate(0.5 * dt);
        rotAngle = -rotationRate;
        inputChanged = true;
    }
    if(sf::Keyboard::isKeyPressed((index == 0) ? sf::Keyboard::W : sf::Keyboard::Up))
    {
        dir.y += -maxSpeed;
        inputChanged = true;
    }
    if(sf::Keyboard::isKeyPressed((index == 0) ? sf::Keyboard::S : sf::Keyboard::Down))
    {
        dir.y += maxSpeed;
        inputChanged = true;
    }
    rotAngle *= dt;
    tr.rotate(rotAngle);
    dir = tr.transformPoint(dir);
    dir.x *= 0.5 * dt;
    dir.y *= 0.5 * dt;

    if (inputChanged)
    {
        Rotate(rotAngle);

        Move(sf::Vector2f(dir.x, 0));
        auto c = level->getCollisions(this);
        if(c.size())
        {
            Move(sf::Vector2f((dir.x > 0 ? -1.0 : 1.0) * c[0].second.width, 0));
        }

        Move(sf::Vector2f(0, dir.y));
        c = level->getCollisions(this);
        if(c.size())
        {
            Move(sf::Vector2f(0, (dir.y > 0 ? -1.0 : 1.0) * c[0].second.height));
        }
        //printf("Input dir: %f %f\r\n", dir.x, dir.y);
    }

    toBullet -= dt;
    if(sf::Keyboard::isKeyPressed((index == 0) ? sf::Keyboard::Space : sf::Keyboard::LControl) && toBullet <= 0)
    {
        toBullet = 500;
        Entity* b = new Bullet(sf::Vector2f(1.0, 1.0));
        b->SetTexture(ResourceCache::LoadTexture("assets/tile.png"));
        b->SetPosition(sprite->getPosition());
        level->Spawn(b);
    }
}
