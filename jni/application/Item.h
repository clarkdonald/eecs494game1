//
//  Item.h
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#ifndef ITEM_H
#define ITEM_H

#include "Game_Object.h"
#include "Terrain.h"
#include <Zeni/Coordinate.h>

class Item : public Game_Object {
  public:
    Item(const Position &position_);
  
    virtual ~Item() = 0;

    virtual bool for_cutting() const;
  
    virtual bool for_extinguishing() const;
  
    virtual bool for_pushing() const;
  
    virtual bool for_water_filling() const;
};

#endif /* ITEM_H */
