//
//  Water.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Water.h"

using namespace Zeni;

Water::Water(const int &floor_, const Point2f &position_)
: Terrain(floor_, position_, true)
{}

void Water::render() const {
  Game_Object::render("water");
}

bool Water::is_crushable() const {
  return true;
}
