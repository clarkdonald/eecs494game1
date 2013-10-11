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
#include <list>

class Terrain : public Game_Object {
  public:
    Terrain(const Position &position_);
  
    virtual ~Terrain() = 0;
  
    virtual void interact(Movable_Object &object_);
  
    virtual bool is_movable_blocking() const;
    
    virtual bool is_terrain_blocking() const;
  
    virtual bool is_droppable() const;
  
    virtual bool is_cuttable() const;
  
    virtual bool is_water_filling() const;
  
    virtual bool is_extinguishable() const;
  
    virtual bool is_crushable() const;
  
    virtual bool is_forced_move() const;
};

#endif /* TERRAIN_H */
