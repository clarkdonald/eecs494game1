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

Item * create_item(const Zeni::String &type_,
                                 const Zeni::Point2f &position_,
                                 const Zeni::Vector2f &size_)
{
  if (type_ == "Axe") {
    return new Axe(position_, size_);
  }
  if (type_ == "Pill") {
    return new Pill(position_, size_);
  }
  else {
    throw new std::bad_alloc;
  }
}
