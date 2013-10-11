//
//  Dumbbell.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Dumbbell.h"

using namespace Zeni;

Dumbbell::Dumbbell(const Position &position_)
: Item(position_)
{}

void Dumbbell::render() const {
  Game_Object::render("pill");
}

bool Dumbbell::for_pushing() const {
  return true;
}
