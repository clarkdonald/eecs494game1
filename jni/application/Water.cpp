//
//  Water.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Water.h"

using namespace Zeni;

Water::Water(const Position &position_)
: Terrain(position_)
{}

void Water::render() const {
  Game_Object::render("water");
}

bool Water::is_movable_blocking() const {
  return true;
}

bool Water::is_water_filling() const {
  return true;
}

bool Water::is_crushable() const {
  return true;
}
