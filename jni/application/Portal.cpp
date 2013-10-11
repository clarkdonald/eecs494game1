//
//  Portal.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Portal.h"

using namespace Zeni;

Portal::Portal(const Position &position_, const Position &destination_position_)
: Terrain(position_),
  destination_position(destination_position_)
{}

void Portal::render() const {
  Game_Object::render("portal");
}

void Portal::interact(Movable_Object &object_) {
  object_.set_position(destination_position);
}

bool Portal::is_forced_move() const {
  return true;
}
