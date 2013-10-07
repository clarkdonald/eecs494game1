//
//  Exit.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Exit.h"

using namespace Zeni;

Exit::Exit(const int &floor_, const Point2f &position_)
: Terrain(floor_, position_, false)
{}

void Exit::render() const {
  Game_Object::render("exit");
}
