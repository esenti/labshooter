//
//  ResourceCache.cpp
//  labshooter
//
//  Created by Pawel Miniszewski on 07.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#include "ResourceCache.h"
#include <string>

std::unordered_map<std::string, sf::Texture*> ResourceCache::Textures;

sf::Texture* ResourceCache::LoadTexture(const std::string& path)
{
    if(!Textures[path])
    {
        Textures[path] = new sf::Texture();
        Textures[path]->loadFromFile(path);
    }
    return Textures[path];
}