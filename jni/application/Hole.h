//
//  Hole.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef HOLE_H
#define HOLE_H

#include "Terrain.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Hole : public Terrain {
  public:
    Hole(const Position &position_);
    
    void render() const;
  
    void interact(Movable_Object &object_) override;
    
    bool is_droppable() const override;
  
    bool is_forced_move() const override;
};

#endif /* HOLE_H */
