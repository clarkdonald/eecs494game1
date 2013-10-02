//
//  Twig.cpp
//  game
//
//  Created by Donald Clark on 10/2/13.
//
//

#include "Twig.h"

using namespace Zeni;

Twig::Twig(const Point2f &position_, const Vector2f &size_)
: Item(position_, size_)
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
