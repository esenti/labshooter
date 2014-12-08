#include "Bullet.h"
#include "ResourceCache.h"
Bullet::Bullet(sf::Vector2f dir): dir(dir)
{
    SetTexture(ResourceCache::LoadTexture("assets/particle.png"));
}

void Bullet::Update(float dt)
{
	Move(dir * dt * 0.5f);
}

std::string Bullet::GetTag()
{
	return "bullet";
}
