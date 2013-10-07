//
//  Pill.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Pill.h"

using namespace Zeni;

Pill::Pill(const int &floor_, const Point2f &position_)
: Item(floor_, position_)
{}

void Pill::render() const {
  Game_Object::render("pill");
}

bool Pill::for_pushing() const {
  return true;
}
