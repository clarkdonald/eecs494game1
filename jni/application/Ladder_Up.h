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
#include "Explorer.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Ladder_Up : public Terrain {
  public:
    Ladder_Up(const int &floor_, const Zeni::Point2f &position_);

    void render() const;

    void interact(Explorer &explorer_);
};

#endif /* LADDER_UP_H */
