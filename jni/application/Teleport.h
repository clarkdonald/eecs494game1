//
//  Teleport.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef TELEPORT_H
#define TELEPORT_H

#include "Terrain.h"
#include "Explorer.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Teleport : public Terrain {
  public:
    Teleport(const Zeni::Point2f &position_,
             const Zeni::Vector2f &size_,
             const Zeni::Point2f &destination_);
    
    void render() const;
    
    void interact(Explorer &explorer_);
  private:
    Zeni::Point2f destination;
};

#endif /* TELEPORT_H */
