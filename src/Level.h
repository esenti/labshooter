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
#include <fstream>
#include <vector>
#include <string>

#define LEVEL_TILE_SIZE 32

class Entity;
class Level
{
private:
    std::vector<Entity*> Entities;
    std::vector<Entity*> PendingDeletion;
    void ParseLevel(std::ifstream& handle);
    
public:
    void LoadLevel(const std::string& path);
    void Render(sf::RenderWindow* window);
    void Update(float dt);
    
    // B - Block
    // 1 - Player 1
    // 2 - Player 2
    void SpawnEntity(char classToSpawn, sf::Vector2f position);
    
    void Spawn(Entity* entity);
    void MarkForDeletion(Entity* ent);
};

#endif /* defined(__labshooter__Level__) */
