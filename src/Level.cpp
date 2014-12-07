//
//  Level.cpp
//  labshooter
//
//  Created by Pawel Miniszewski on 07.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#include "Level.h"
#include "Entity.h"
#include "Entities/Player.h"
#include "ResourceCache.h"
#include <stdio.h>
void Level::ParseLevel(FILE* handle)
{
    //int filesize = fseek(handle, 0, 2);
    fseek(handle, 0, 0);
    int ch = -1;
    do
    {
        ch = fgetc(handle);
    }while(ch != EOF);
    
}

void Level::LoadLevel(const std::string& path)
{
    /*Entity* p1 = new Player(0);
    p1->SetTexture(ResourceCache::LoadTexture("assets/player.png"));
    Spawn(p1);

    Entity* p2 = new Player(1);
    p2->SetTexture(ResourceCache::LoadTexture("assets/player.png"));
    Entities.push_back(p2);*/
    
    FILE* f = fopen(path.c_str(), "r");
    if(f)
    {
        ParseLevel(f);
    }
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

void Level::Spawn(Entity* entity)
{
    entity->SetLevel(this);
    Entities.push_back(entity);
}
