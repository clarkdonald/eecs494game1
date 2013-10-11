//
//  Ground.cpp
//  game
//
//  Created by Donald Clark on 10/4/13.
//
//

#include "Ground.h"

using namespace Zeni;

Ground::Ground(const Position &position_)
: Terrain(position_)
{}

void Ground::render() const {
  Game_Object::render("ground");
}
