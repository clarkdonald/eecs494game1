//
//  Boulder.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef BOULDER_H
#define BOULDER_H

#include "Terrain.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Boulder : public Terrain {
  public:
    Boulder(const Position &position_);
    
    void render() const;
  
    bool is_movable_blocking() const override;
  
    bool is_terrain_blocking() const override;
};

#endif /* BOULDER_H */
