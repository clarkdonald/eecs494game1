//
//  Fire.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Fire.h"

using namespace Zeni;

Fire::Fire(const Position &position_)
: Terrain(position_)
{}

void Fire::render() const {
  Game_Object::render("fire");
}

bool Fire::is_movable_blocking() const {
  return true;
}

bool Fire::is_terrain_blocking() const {
  return true;
}

bool Fire::is_extinguishable() const {
  return true;
}
