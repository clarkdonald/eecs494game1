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
#include "Explorer.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Portal : public Terrain {
  public:
    Portal(const int &floor_,
           const Zeni::Point2f &position_,
           const int &destination_floor_,
           const Zeni::Point2f &destination_position_);
    
    void render() const;
    
    void interact(Explorer &explorer_);
  
  private:
    int destination_floor;
    Zeni::Point2f destination_position;
};

#endif /* Portal_H */
