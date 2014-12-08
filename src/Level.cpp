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
#include "Entities/Block.h"
#include "Entities/Turret.h"
#include "ResourceCache.h"


Level::Level()
{
    font.loadFromFile("assets/visitor1.ttf");
    over.setFont(font);
    over.setString("GAME OVER");
    over.setCharacterSize(80);
    over.setColor(sf::Color::Black);
    over.setStyle(sf::Text::Regular);
    sf::FloatRect textRect = over.getLocalBounds();
    over.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    over.setPosition(sf::Vector2f(800/2.0f, 600/2.0f));

    space.setFont(font);
    space.setString("SPACE TO START");
    space.setCharacterSize(80);
    space.setColor(sf::Color::Black);
    space.setStyle(sf::Text::Regular);
    textRect = space.getLocalBounds();
    space.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    space.setPosition(sf::Vector2f(800/2.0f, 600/2.0f));
}

void Level::ParseLevel(std::ifstream& handle)
{
    //int filesize = fseek(handle, 0, 2);
    int tileX = 0;
    int tileY = 0;
    while (!handle.eof()) {

        std::string line;
        std::getline(handle, line);
        for(unsigned int i=0;i<line.length();i++)
        {
            char tile = line.at(i);
            sf::Vector2f pos(tileX * LEVEL_TILE_SIZE + 0.5 * LEVEL_TILE_SIZE,
                tileY * LEVEL_TILE_SIZE + 0.5 * LEVEL_TILE_SIZE);
            SpawnEntity(tile, pos);

            tileX++;
        }
        tileY++;
        tileX = 0;

    }
}

void Level::LoadLevel(const std::string& path)
{
    /*Entity* p1 = new Player(0);
    p1->SetTexture(ResourceCache::LoadTexture("assets/player.png"));
    Spawn(p1);

    Entity* p2 = new Player(1);
    p2->SetTexture(ResourceCache::LoadTexture("assets/player.png"));
    Entities.push_back(p2);*/
    std::ifstream file;
    file.open(path);
    if(file.is_open())
    {
        ParseLevel(file);
    }
}

void Level::Render(sf::RenderWindow* window)
{
    for(auto& it : Entities )
    {
        it->Draw(window);
    }

    if(state == OVER)
    {
        window->draw(over);
    }
    else if(state == MENU)
    {
        window->draw(space);
    }
}
void Level::Update(float dt)
{
    switch(state)
    {
    case MENU:
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            SetState(PLAYING);
        }
        break;
    case OVER:
        break;
    case PLAYING:
        for(unsigned int i = 0; i < Entities.size(); ++i)
        {
            Entities[i]->Update(dt);
        }

        if(PendingDeletion.size() > 0)
        {
            for(auto& e : PendingDeletion)
            {
                Entities.erase(std::remove(Entities.begin(), Entities.end(), e), Entities.end());

                delete e;
            }
        PendingDeletion.clear();
        }
        break;
    }
}

void Level::SpawnEntity(char classToSpawn, sf::Vector2f position)
{
    Entity* e = nullptr;
    switch (classToSpawn) {
        case 'B':
            e = new Block();
            break;
        case '1':
            e = new Player(0);
            e->SetTexture(ResourceCache::LoadTexture("assets/player1.png"));
            player1 = e;
            break;
        case '2':
            e = new Player(1);
            e->SetTexture(ResourceCache::LoadTexture("assets/player2.png"));
            player2 = e;
            break;
        case 'T':
            e = new Turret(0);
            break;
        case 't':
            e = new Turret(1);
            break;

        default:
            break;
    }
    if(e)
    {
        e->SetPosition(position);
        Spawn(e);
    }
}

void Level::Spawn(Entity* entity)
{
    entity->SetLevel(this);
    Entities.push_back(entity);
}
void Level::MarkForDeletion(Entity* ent)
{
    PendingDeletion.push_back(ent);
}

std::vector<std::pair<Entity*, sf::FloatRect>> Level::getCollisions(Entity* entity)
{
    std::vector<std::pair<Entity*, sf::FloatRect>> result;

    sf::FloatRect collision;

    for(auto e : Entities)
    {
        if(entity->CollidesWith(e, collision))
        {
            result.push_back(std::make_pair(e, collision));
        }
    }

    return result;
}

void Level::SetState(Level::State s)
{
    state = s;
}
