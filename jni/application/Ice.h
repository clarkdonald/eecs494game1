//
//  Ice.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef ICE_H
#define ICE_H

#include "Terrain.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Ice : public Terrain {
  public:
    Ice(const Position &position_);
    
    void render() const;
    
    void interact(Movable_Object &object_) override;
    
    bool is_forced_move() const override;
};

#endif /* ICE_H */
