//
//  Item_Factory.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef ITEM_FACTORY_H
#define ITEM_FACTORY_H

#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Item;

Item * create_item(const Zeni::String &type_, const Position &position_);

#endif /* TERRAIN_FACTORY_H */
