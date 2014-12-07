//
//  Entity.cpp
//  labshooter
//
//  Created by Pawel Miniszewski on 07.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#include "Entity.h"

Entity::Entity()
{
    sprite = nullptr;
}

Entity::~Entity()
{
    delete sprite;
}

void Entity::Draw(sf::RenderWindow* window)
{
    if(window && sprite &&  sprite->getTexture())
    {

        window->draw(*sprite);
    }
}
void Entity::Update(float dt)
{

}

void Entity::Move(sf::Vector2f delta)
{
    //position += delta;
    sprite->move(delta);

    //if(sprite->getGlobalBounds().intersects(obstacle.getGlobalBounds()))
    //{
        //sprite->move(-delta);
    //}
}

void Entity::SetPosition(sf::Vector2f absolutePosition)
{
    if(sprite)
    {
        sprite->setPosition(absolutePosition);
    }

}
void Entity::SetTexture(sf::Texture* texture)
{
    if(!sprite)
    {
        sprite = new sf::Sprite();
    }
    if( texture)
    {
        sprite->setTexture(*texture);
    }
}

