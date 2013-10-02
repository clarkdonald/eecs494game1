//
//  Boulder.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Boulder.h"

using namespace Zeni;

Boulder::Boulder(const Point2f &position_, const Vector2f &size_)
: Terrain(position_, size_, true)
{}

void Boulder::render() const {
  Game_Object::render("boulder");
}

bool Boulder::is_pushable() const {
  return true;
}
