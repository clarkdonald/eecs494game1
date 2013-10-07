//
//  Ladder_Up.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Ladder_Up.h"

using namespace Zeni;

Ladder_Up::Ladder_Up(const int &floor_, const Point2f &position_)
: Terrain(floor_, position_, false)
{}

void Ladder_Up::render() const {
  Game_Object::render("ladder_u");
}

void Ladder_Up::interact(Explorer &explorer_) {
  explorer_.set_floor(explorer_.get_floor() + 1);
}
