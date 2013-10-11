//
//  Hole.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Hole.h"
#include <list>

using std::list;

using namespace Zeni;

Hole::Hole(const Position &position_)
: Terrain(position_)
{}

void Hole::render() const {
  Game_Object::render("hole");
}

void Hole::interact(Movable_Object &object_) {
  Position pos = object_.get_position();
  pos.floor -= 1;
  object_.set_position(pos);
}

bool Hole::is_droppable() const {
  return true;
}

bool Hole::is_forced_move() const {
  return true;
}
