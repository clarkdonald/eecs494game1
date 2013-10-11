//
//  Exit.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Exit.h"

using namespace Zeni;

Exit::Exit(const Position &position_)
: Terrain(position_)
{}

void Exit::render() const {
  Game_Object::render("exit");
}
