//
//  Ladder_Down.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Ladder_Down.h"

using namespace Zeni;

Ladder_Down::Ladder_Down(const int &floor_, const Point2f &position_)
: Terrain(floor_, position_, false)
{}

void Ladder_Down::render() const {
  Game_Object::render("ladder_d");
}

void Ladder_Down::interact(Explorer &explorer_) {
  explorer_.set_floor(explorer_.get_floor() - 1);
}
