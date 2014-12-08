#include "Bullet.h"

Bullet::Bullet(sf::Vector2f dir): dir(dir)
{

}

void Bullet::Update(float dt)
{
	Move(dir * dt * 1.0f);
}

std::string Bullet::GetTag()
{
	return "bullet";
}
