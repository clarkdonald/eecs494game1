//
//  Ground.cpp
//  game
//
//  Created by Donald Clark on 10/4/13.
//
//

#include "Ground.h"

using namespace Zeni;

Ground::Ground(const int &floor_, const Point2f &position_)
: Terrain(floor_, position_, false)
{}

void Ground::render() const {
  Game_Object::render("ground");
}
