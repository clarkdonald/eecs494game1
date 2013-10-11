//
//  Ladder_Up.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef LADDER_UP_H
#define LADDER_UP_H

#include "Terrain.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Ladder_Up : public Terrain {
  public:
    Ladder_Up(const Position &position_);

    void render() const;
  
    void interact(Movable_Object &object_) override;
  
    bool is_terrain_blocking() const override;

    bool is_forced_move() const override;
};

#endif /* LADDER_UP_H */
