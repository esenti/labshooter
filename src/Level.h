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
public:
    enum State {
        MENU,
        PLAYING,
        OVER,
        WIN,
    };

private:
    std::vector<Entity*> Entities;
    std::vector<Entity*> PendingDeletion;
    void ParseLevel(std::ifstream& handle);
    State state;
    sf::Text over;
    sf::Text space;
    sf::Text win;
    sf::Font font;

public:
    Level();
    void LoadLevel(const std::string& path);
    void Render(sf::RenderWindow* window);
    void Update(float dt);
    void MarkForDeletion(Entity* ent);
    // T - Turret
    // B - Block
    // 1 - Player 1
    // 2 - Player 2
    void SpawnEntity(char classToSpawn, sf::Vector2f position);

    void Spawn(Entity* entity);
    std::vector<std::pair<Entity*, sf::FloatRect>> getCollisions(Entity* entity);
    void SetState(State s);

    Entity* player1;
    Entity* player2;
};

#endif /* defined(__labshooter__Level__) */
