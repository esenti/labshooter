#ifndef __labshooter__Bullet__
#define __labshooter__Bullet__

#include "Entity.h"

class Bullet : public Entity
{
public:
    Bullet(sf::Vector2f dir);
    virtual void Update(float dt) override;

protected:
	sf::Vector2f dir;
};
#endif /* defined(__labshooter__Bullet__) */
