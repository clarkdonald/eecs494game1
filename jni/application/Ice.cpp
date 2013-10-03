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

Ice::Ice(const int &floor_,
         const Point2f &position_,
         const Vector2f &size_)
: Terrain(floor_, position_, size_, false)
{}

void Ice::render() const {
  Game_Object::render("ice");
}

void Ice::interact(Explorer &explorer_) {
  Point2f pos = explorer_.get_position();
  
  switch (explorer_.get_direction()) {
    case UP:
      pos.y -= 4.0f;
      break;
      
    case DOWN:
      pos.y += 4.0f;
      break;
      
    case LEFT:
      pos.x -= 4.0f;
      break;
      
    case RIGHT:
      pos.x += 4.0f;
      break;
      
    default:
      throw new bad_exception;
      break;
  }
  
  explorer_.set_sliding(true);
  explorer_.set_position(pos);
}
