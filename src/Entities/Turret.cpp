#include "Turret.h"
#include "ResourceCache.h"
#include "Level.h"
#include "Bullet.h"

Turret::Turret(): toBullet(300)
{
    SetTexture(ResourceCache::LoadTexture("assets/turret.png"));
}

std::string Turret::GetTag()
{
	return "enemy";
}

float distance(sf::Vector2f a, sf::Vector2f b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

sf::Vector2f normalize(const sf::Vector2f& source)
{
    float length = sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0)
        return sf::Vector2f(source.x / length, source.y / length);
    else
        return source;
}

#include <iostream>
void Turret::Update(float dt)
{
	toBullet -= dt;

	if(toBullet <= 0)
	{
		float dist1 = distance(sprite->getPosition(), level->player1->sprite->getPosition());
		float dist2 = distance(sprite->getPosition(), level->player2->sprite->getPosition());

		Entity* target = dist1 < dist2 ? level->player1 : level->player2;

		sf::Vector2f toTarget = normalize(target->sprite->getPosition() - sprite->getPosition());

		sf::Transform transform;
		transform.rotate(180);
		toBullet = 300;
		// Entity* b = new Bullet(transform.transformPoint(sf::Vector2f(0.0, -1.0)));
		Entity* b = new Bullet(toTarget);
		b->SetTexture(ResourceCache::LoadTexture("assets/particle.png"));
		b->SetPosition(sprite->getPosition());
		level->Spawn(b);
	}
}
