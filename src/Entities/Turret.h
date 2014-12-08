#ifndef __labshooter__Turret__
#define __labshooter__Turret__

#include "Entity.h"
class Turret : public Entity
{
public:
    Turret();
    virtual std::string GetTag();
    virtual void Update(float dt) override;

protected:
   	int toBullet;
};
#endif /* defined(__labshooter__Turret__) */
