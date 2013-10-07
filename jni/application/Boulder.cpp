//
//  Boulder.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Boulder.h"

using namespace Zeni;

Boulder::Boulder(const int &floor_, const Point2f &position_)
: Terrain(floor_, position_, true)
{}

void Boulder::render() const {
  Game_Object::render("boulder");
}

bool Boulder::is_pushable() const {
  return true;
}
