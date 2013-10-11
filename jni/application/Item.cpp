//
//  Item.cpp
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#include "Item.h"

Item::Item(const Position &position_)
: Game_Object(position_)
{}

Item::~Item() {}

bool Item::for_cutting() const {
  return false;
}

bool Item::for_pushing() const {
  return false;
}

bool Item::for_extinguishing() const {
  return true;
}

bool Item::for_water_filling() const {
  return true;
}
