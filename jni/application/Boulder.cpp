//
//  Boulder.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Boulder.h"

using namespace Zeni;

Boulder::Boulder(const Position &position_)
: Terrain(position_)
{}

void Boulder::render() const {
  Game_Object::render("boulder");
}

bool Boulder::is_movable_blocking() const {
  return true;
}

bool Boulder::is_terrain_blocking() const {
  return true;
}
