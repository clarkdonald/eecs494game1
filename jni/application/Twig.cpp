//
//  Twig.cpp
//  game
//
//  Created by Donald Clark on 10/2/13.
//
//

#include "Twig.h"

using namespace Zeni;

Twig::Twig(const int &floor_, const Point2f &position_)
: Item(floor_, position_)
{}

void Twig::render() const {
  Game_Object::render("twig");
}

bool Twig::for_burning() const {
  return true;
}

bool Twig::for_lighting() const {
  return true;
}
