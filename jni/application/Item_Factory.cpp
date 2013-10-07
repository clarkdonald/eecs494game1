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
                   const int &floor_,
                   const Zeni::Point2f &position_)
{
  if (type_ == "Axe") {
    return new Axe(floor_, position_);
  }
  if (type_ == "Pill") {
    return new Pill(floor_, position_);
  }
  if (type_ == "Twig") {
    return new Twig(floor_, position_);
  }
  else {
    throw new std::bad_alloc;
  }
}
