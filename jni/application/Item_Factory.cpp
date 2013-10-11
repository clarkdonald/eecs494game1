//
//  Item_Factory.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Item_Factory.h"
#include "Item_Includes.h"

using std::bad_alloc;

Item * create_item(const Zeni::String &type_, const Position &position_)
{
  if (type_ == "Axe") return new Axe(position_);
  else if (type_ == "Dumbbell") return new Dumbbell(position_);
  else if (type_ == "Bucket") return new Bucket(position_);
  else throw new std::bad_alloc;
}
