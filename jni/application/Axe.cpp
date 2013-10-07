//
//  Axe.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Axe.h"

using namespace Zeni;

Axe::Axe(const int &floor_, const Point2f &position_)
: Item(floor_, position_)
{}

void Axe::render() const {
  Game_Object::render("axe");
}

bool Axe::for_cutting() const {
  return true;
}
