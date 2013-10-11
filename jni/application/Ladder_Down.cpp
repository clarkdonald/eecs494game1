//
//  Ladder_Down.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Ladder_Down.h"

using namespace Zeni;

Ladder_Down::Ladder_Down(const Position &position_)
: Terrain(position_)
{}

void Ladder_Down::render() const {
  Game_Object::render("ladder_d");
}

void Ladder_Down::interact(Movable_Object &object_) {
  Position pos = object_.get_position();
  pos.floor -= 1;
  object_.set_position(pos);
}

bool Ladder_Down::is_terrain_blocking() const {
  return true;
}

bool Ladder_Down::is_forced_move() const {
  return true;
}
