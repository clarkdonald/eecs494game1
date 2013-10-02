//
//  Terrain.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef TERRAIN_H
#define TERRAIN_H

#include "Game_Object.h"
#include "Explorer.h"
#include "Utility.h"
#include <Zeni/Coordinate.h>

class Terrain : public Game_Object {
  public:
    Terrain(const Zeni::Point2f &position_,
            const Zeni::Vector2f &size_,
            const bool &blocking_);
  
    virtual ~Terrain() = 0;
  
    virtual void interact(Explorer &explorer);
  
    virtual bool is_cuttable() const;
  
    virtual bool is_burnable() const;
  
    virtual bool is_pushable() const;
  
    virtual bool is_crushable() const;
};


#endif /* TERRAIN_H */
