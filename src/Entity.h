//
//  Entity.h
//  labshooter
//
//  Created by Pawel Miniszewski on 07.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#ifndef __labshooter__Entity__
#define __labshooter__Entity__

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Level;

class Entity
{
protected:
    bool hasMoved;
    sf::Sprite* sprite;
    Level* level;

public:
    Entity();
    virtual ~Entity();
    virtual void Draw(sf::RenderWindow* window);
    virtual void Update(float dt);
    void Move(sf::Vector2f delta); //Move character to given position
    void Rotate(float angle);
    void SetPosition(sf::Vector2f absolutePosition);
    void SetTexture(sf::Texture* texture);
    void SetLevel(Level* l);
    sf::Transform GetTransform();
    float GetRotation();
};
#endif /* defined(__labshooter__Entity__) */
