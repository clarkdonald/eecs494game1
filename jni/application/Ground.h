//
//  Ground.h
//  game
//
//  Created by Donald Clark on 10/4/13.
//
//

#ifndef GROUND_H
#define GROUND_H

#include "Terrain.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Ground : public Terrain {
  public:
    Ground(const Position &position_);
    
    void render() const;
};

#endif /* GROUND_H */
