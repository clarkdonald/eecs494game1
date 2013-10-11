//
//  Ice.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Ice.h"

using namespace Zeni;
using std::bad_exception;

Ice::Ice(const Position &position_)
: Terrain(position_)
{}

void Ice::render() const {
  Game_Object::render("ice");
}

void Ice::interact(Movable_Object &object_) {
  Position pos = object_.get_position();
  if (!object_.is_sliding()) {
    object_.set_sliding(object_.get_direction());
  
    switch (object_.get_direction()) {
      case UP:
        pos.position.y -= 4.0f;
        break;
        
      case DOWN:
        pos.position.y += 4.0f;
        break;
        
      case LEFT:
        pos.position.x -= 4.0f;
        break;
        
      case RIGHT:
        pos.position.x += 4.0f;
        break;
        
      default:
        throw new bad_exception;
        break;
    }
  }
  else {
    switch (object_.get_sliding_direction()) {
      case UP:
        pos.position.y -= 4.0f;
        break;

      case DOWN:
        pos.position.y += 4.0f;
        break;

      case LEFT:
        pos.position.x -= 4.0f;
        break;

      case RIGHT:
        pos.position.x += 4.0f;
        break;

      default:
        throw new bad_exception;
        break;
    }
  }
  
  object_.set_position(pos);
}

bool Ice::is_forced_move() const {
  return true;
}
