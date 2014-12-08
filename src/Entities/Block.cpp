//
//  Block.cpp
//  labshooter
//
//  Created by Pawel Miniszewski on 07.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#include "Block.h"
#include "ResourceCache.h"
Block::Block()
{
    SetTexture(ResourceCache::LoadTexture("assets/tile.png"));
}

std::string Block::GetTag()
{
	return "environment";
}
