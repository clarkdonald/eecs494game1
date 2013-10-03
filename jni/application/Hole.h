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
#include "Explorer.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Hole : public Terrain {
  public:
    Hole(const int &floor_,
         const Zeni::Point2f &position_,
         const Zeni::Vector2f &size_);
    
    void render() const;
    
    void interact(Explorer &explorer_);
};

#endif /* HOLE_H */