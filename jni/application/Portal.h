//
//  Portal.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef PORTAL_H
#define PORTAL_H

#include "Terrain.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Portal : public Terrain {
  public:
    Portal(const Position &position_, const Position &destination_position_);
    
    void render() const;
  
    void interact(Movable_Object &object_) override;
  
    bool is_forced_move() const override;
      
  private:
    Position destination_position;
};

#endif /* Portal_H */
