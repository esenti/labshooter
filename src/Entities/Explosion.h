//
//  Explosion.h
//  labshooter
//
//  Created by Pawel Miniszewski on 08.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#ifndef __labshooter__Explosion__
#define __labshooter__Explosion__

#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <string>

#define FLOAT_RAND static_cast <float> (rand()) / static_cast <float> (RAND_MAX)

struct ExplosionParticle;


struct ExplosionParticle
{

    sf::Sprite sprite;
    sf::Vector2f velocity;
    float elapsedTime;
    float timeToLive;
};

class Explosion : public Entity
{
private:
    std::vector<ExplosionParticle*> particles;
    int spawnedParticles;
    sf::Vector2f Origin;
public:
    Explosion();
    virtual ~Explosion();
    virtual void Draw(sf::RenderWindow* window) override;
    virtual void Update(float dt) override;
    virtual std::string GetTag() override;
    void Fire(sf::Vector2f& pos);
    void OnParticleDie(ExplosionParticle* particle);



};
#endif /* defined(__labshooter__Explosion__) */
