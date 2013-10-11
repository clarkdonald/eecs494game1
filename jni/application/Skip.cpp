//
//  Skip.cpp
//  game
//
//  Created by Donald Clark on 10/10/13.
//
//

#include "Skip.h"

using namespace Zeni;

Skip::Skip(const Position &position_)
: Terrain(position_)
{}

void Skip::render() const {
  Game_Object::render("skip");
}
