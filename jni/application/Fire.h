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
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Fire : public Terrain {
  public:
    Fire(const Position &position_);
    
    void render() const;
  
    bool is_movable_blocking() const override;
  
    bool is_terrain_blocking() const override;
  
    bool is_extinguishable() const override;
};

#endif /* FIRE_H */
