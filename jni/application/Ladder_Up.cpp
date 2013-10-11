//
//  Ladder_Up.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Ladder_Up.h"

using namespace Zeni;

Ladder_Up::Ladder_Up(const Position &position_)
: Terrain(position_)
{}

void Ladder_Up::render() const {
  Game_Object::render("ladder_u");
}

void Ladder_Up::interact(Movable_Object &object_) {
  Position pos = object_.get_position();
  pos.floor += 1;
  object_.set_position(pos);
}

bool Ladder_Up::is_terrain_blocking() const {
  return true;
}

bool Ladder_Up::is_forced_move() const {
  return true;
}
