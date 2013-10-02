//
//  Water.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Water.h"

using namespace Zeni;

Water::Water(const Point2f &position_, const Vector2f &size_)
: Terrain(position_, size_, true)
{}

void Water::render() const {
  Game_Object::render("water");
}

bool Water::is_crushable() const {
  return true;
}
