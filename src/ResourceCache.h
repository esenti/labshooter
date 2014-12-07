//
//  ResourceCache.h
//  labshooter
//
//  Created by Pawel Miniszewski on 07.12.2014.
//  Copyright (c) 2014 Pawel Miniszewski. All rights reserved.
//

#ifndef __labshooter__ResourceCache__
#define __labshooter__ResourceCache__

#include <stdio.h>
#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
class ResourceCache
{
private:
    static std::unordered_map<std::string, sf::Texture*> Textures;
public:
    static sf::Texture* LoadTexture(const std::string& path);
    
};

#endif /* defined(__labshooter__ResourceCache__) */
