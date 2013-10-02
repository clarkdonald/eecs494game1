//
//  Exit.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef EXIT_H
#define EXIT_H

#include "Terrain.h"
#include "Explorer.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Exit : public Terrain {
public:
  Exit(const Zeni::Point2f &position_, const Zeni::Vector2f &size_);
  
  void render() const;
};

#endif /* EXIT_H */
