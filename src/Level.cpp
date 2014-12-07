//
//  Level.cpp
//  labshooter
//
//  Created by Pawel Miniszewski on 07.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#include "Level.h"
#include "Entity.h"
#include "Player.h"
#include "ResourceCache.h"

void Level::LoadLevel(std::string path)
{
    Entity* p1 = new Player();
    p1->SetTexture(ResourceCache::LoadTexture("assets/player.png"));
    Entities.push_back(p1);
}

void Level::Render(sf::RenderWindow* window)
{
    for(auto& it : Entities )
    {
        it->Draw(window);
    }
    
}
void Level::Update(float dt)
{
    for(auto& it : Entities )
    {
        it->Update(dt);
    }
}