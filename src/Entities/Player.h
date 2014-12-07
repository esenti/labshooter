//
//  Player.h
//  labshooter
//
//  Created by Pawel Miniszewski on 07.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#ifndef __labshooter__Player__
#define __labshooter__Player__

#include <stdio.h>
#include "Entity.h"
class Player : public Entity
{
public:
    Player(int i);
    virtual ~Player();
    virtual void Update(float dt) override;

protected:
	int index;
	int toBullet = 500;
};
#endif /* defined(__labshooter__Player__) */
