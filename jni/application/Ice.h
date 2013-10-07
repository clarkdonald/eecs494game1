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
#include "Explorer.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Ice : public Terrain {
public:
  Ice(const int &floor_, const Zeni::Point2f &position_);
  
  void render() const;
  
  void interact(Explorer &explorer_);
};

#endif /* ICE_H */
