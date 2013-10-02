//
//  Ladder_Down.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Ladder_Down.h"

using namespace Zeni;

Ladder_Down::Ladder_Down(const Point2f &position_, const Vector2f &size_)
: Terrain(position_, size_, false)
{}

void Ladder_Down::render() const {
  Game_Object::render("ladder_d");
}

void Ladder_Down::interact(Explorer &explorer_) {
  //explorer.set_position(Point2f(0.0f, 0.0f));
}
