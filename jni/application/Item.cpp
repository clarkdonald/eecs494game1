//
//  Item.cpp
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#include "Item.h"

Item::Item(const int &floor_, const Zeni::Point2f &position_)
: Game_Object(floor_, position_, false)
{}

Item::~Item() {}

bool Item::for_cutting() const {
  return false;
}

bool Item::for_burning() const {
  return false;
}

bool Item::for_pushing() const {
  return false;
}

bool Item::for_lighting() const {
  return false;
}
