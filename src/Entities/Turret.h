#ifndef __labshooter__Turret__
#define __labshooter__Turret__

#include "Entity.h"
class Turret : public Entity
{
public:
    Turret(int index);
    virtual std::string GetTag();
    virtual void Update(float dt) override;
    virtual void Hit(float dmg, int i);

protected:
   	int toBullet;
   	int index;
   	float hp;
};
#endif /* defined(__labshooter__Turret__) */
