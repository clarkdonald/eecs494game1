//
//  Ladder_Down.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef LADDER_DOWN_H
#define LADDER_DOWN_H

#include "Terrain.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Ladder_Down : public Terrain {
  public:
    Ladder_Down(const Position &position_);
    
    void render() const;
  
    void interact(Movable_Object &object_) override;
    
    bool is_terrain_blocking() const override;
  
    bool is_forced_move() const override;
};

#endif /* LADDER_DOWN_H */
