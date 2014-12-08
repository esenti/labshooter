//
//  Explosion.cpp
//  labshooter
//
//  Created by Pawel Miniszewski on 08.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#include "Explosion.h"
#include "ResourceCache.h"
#include <time.h>

Explosion::Explosion()
{
    int particleNum = rand() & 60 + 35;
    spawnedParticles = particleNum;
    const sf::Texture* particleTexture = ResourceCache::LoadTexture("assets/particle.png");
    for(int i=0;i<particleNum;i++)
    {
        float rand01Scale = FLOAT_RAND;
        float scale = rand01Scale * 7.0f + 1;
        ExplosionParticle* particle = new ExplosionParticle;
        particle->sprite.setScale(scale, scale);
        particle->sprite.setTexture(*particleTexture);
        particle->sprite.setPosition(200, 200);
        
        sf::Transform tr;
        tr.rotate(FLOAT_RAND * 359.0f);
        float randomSpeed = FLOAT_RAND * 1;
        particle->velocity = sf::Vector2f(tr.transformPoint(1, 0))*randomSpeed;
        particle -> timeToLive = FLOAT_RAND * 2;
        particles.push_back(particle);
        
        
    }
}

Explosion::~Explosion()
{
    
}

void Explosion::Draw(sf::RenderWindow* window)
{
    for(auto& p : particles)
    {
        if(p)
        {
            window->draw(p->sprite);
        }
    }
}
void Explosion::Update(float dt)
{
    for(auto& p : particles)
    {
        p->sprite.move(p->velocity * dt);
        
        p->elapsedTime += dt;
        if(p->elapsedTime > p->timeToLive)
        {
            spawnedParticles--;
        }
        
    }
    
    if(spawnedParticles <= 0)
    {
        Destroy();
    }
}

std::string Explosion::GetTag()
{
    return "Particles";
}

void Explosion::OnParticleDie(ExplosionParticle* particle)
{
    delete particle;
}


