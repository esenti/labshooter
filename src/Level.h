//
//  Level.h
//  labshooter
//
//  Created by Pawel Miniszewski on 07.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#ifndef __labshooter__Level__
#define __labshooter__Level__

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>
#include <string>

class Entity;
class Level
{
private:
    std::vector<Entity*> Entities;

public:
    void LoadLevel(std::string path);
    void Render(sf::RenderWindow* window);
    void Update(float dt);
    void Spawn(Entity* entity);
};

#endif /* defined(__labshooter__Level__) */
