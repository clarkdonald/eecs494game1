//
//  Hole.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Hole.h"

using namespace Zeni;

Hole::Hole(const int &floor_, const Point2f &position_)
: Terrain(floor_, position_, false)
{}

void Hole::render() const {
  Game_Object::render("hole");
}

void Hole::interact(Explorer &explorer_) {
  explorer_.set_floor(explorer_.get_floor() - 1);
}
