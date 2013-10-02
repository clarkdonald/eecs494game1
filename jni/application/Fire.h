//
//  Fire.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef FIRE_H
#define FIRE_H

#include "Terrain.h"
#include "Explorer.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Fire : public Terrain {
  public:
    Fire(const Zeni::Point2f &position_, const Zeni::Vector2f &size_);
    
    void render() const;
};

#endif /* FIRE_H */
