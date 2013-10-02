//
//  Fire.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Fire.h"

using namespace Zeni;

Fire::Fire(const Point2f &position_, const Vector2f &size_)
: Terrain(position_, size_, true)
{}

void Fire::render() const {
  Game_Object::render("fire");
}
