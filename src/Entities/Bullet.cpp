#include "Bullet.h"
#include "ResourceCache.h"
#include "Level.h"

Bullet::Bullet(sf::Vector2f dir): dir(dir)
{
    SetTexture(ResourceCache::LoadTexture("assets/particle.png"));
}

void Bullet::Update(float dt)
{
	Move(dir * dt * 0.5f);
	auto collisions = level->getCollisions(this);

	if(collisions.size())
	{
		collisions[0].first->Hit(5);
		level->MarkForDeletion(this);
	}
}

std::string Bullet::GetTag()
{
	return "bullet";
}

bool Bullet::CollidesWith(Entity* e, sf::FloatRect& collision)
{
    return (e->GetTag() == "environment" || e->GetTag() == "player") && sprite->getGlobalBounds().intersects(e->sprite->getGlobalBounds(), collision);
}
