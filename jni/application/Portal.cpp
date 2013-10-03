//
//  Portal.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Portal.h"

using namespace Zeni;

Portal::Portal(const int &floor_,
               const Zeni::Point2f &position_,
               const Zeni::Vector2f &size_,
               const int &destination_floor_,
               const Zeni::Point2f &destination_position_)
: Terrain(floor_, position_, size_, false),
  destination_floor(destination_floor_),
  destination_position(destination_position_)
{}

void Portal::render() const {
  Game_Object::render("portal");
}

void Portal::interact(Explorer &explorer_) {
  explorer_.set_position(destination_position);
  explorer_.set_floor(destination_floor);
}
