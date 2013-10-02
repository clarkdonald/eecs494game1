//
//  Ladder_Up.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Ladder_Up.h"

using namespace Zeni;

Ladder_Up::Ladder_Up(const Point2f &position_, const Vector2f &size_)
: Terrain(position_, size_, false)
{}

void Ladder_Up::render() const {
  Game_Object::render("ladder_u");
}

void Ladder_Up::interact(Explorer &explorer_) {
  //explorer.set_position(Point2f(0.0f, 0.0f));
}
