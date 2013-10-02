//
//  Hole.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Hole.h"

using namespace Zeni;

Hole::Hole(const Point2f &position_, const Vector2f &size_)
: Terrain(position_, size_, false)
{}

void Hole::render() const {
  Game_Object::render("hole");
}

void Hole::interact(Explorer &explorer_) {
  //explorer.set_position(Point2f(0.0f, 0.0f));
}
