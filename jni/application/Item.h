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
    Item(const int &floor_, const Zeni::Point2f &position_);
  
    virtual ~Item() = 0;

    virtual bool for_cutting() const;
  
    virtual bool for_burning() const;
  
    virtual bool for_pushing() const;
  
    virtual bool for_lighting() const;
};

#endif /* ITEM_H */
