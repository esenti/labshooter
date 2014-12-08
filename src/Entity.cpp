//
//  Entity.cpp
//  labshooter
//
//  Created by Pawel Miniszewski on 07.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#include "Entity.h"
#include "Level.h"

Entity::Entity() : sprite(nullptr)
{
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
void Entity::Rotate(float angle)
{
    sprite->rotate(angle);
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
        sf::Vector2u s = texture->getSize();
        sf::Vector2f origin = sf::Vector2f((float)s.x, (float)s.y)/2.0f;
        sprite->setOrigin(origin);
    }
}

void Entity::SetLevel(Level* l)
{
    level = l;
}

bool Entity::CollidesWith(Entity* e, sf::FloatRect& collision)
{
    return e != this && sprite->getGlobalBounds().intersects(e->sprite->getGlobalBounds(), collision);
}

sf::Transform Entity::GetTransform()
{
    return sprite->getTransform();
}
float Entity::GetRotation()
{
    return sprite->getRotation();
}
