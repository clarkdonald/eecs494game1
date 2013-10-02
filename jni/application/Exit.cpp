//
//  Exit.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Exit.h"

using namespace Zeni;

Exit::Exit(const Point2f &position_, const Vector2f &size_)
: Terrain(position_, size_, false)
{}

void Exit::render() const {
  Game_Object::render("exit");
}
