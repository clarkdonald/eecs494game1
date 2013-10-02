//
//  Teleport.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Teleport.h"

using namespace Zeni;

Teleport::Teleport(const Point2f &position_,
                   const Vector2f &size_,
                   const Zeni::Point2f &destination_)
: Terrain(position_, size_, false),
  destination(destination_)
{}

void Teleport::render() const {
  Game_Object::render("teleport");
}

void Teleport::interact(Explorer &explorer_) {
  explorer_.set_position(destination);
}
