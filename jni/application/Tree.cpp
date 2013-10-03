//
//  Tree.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Tree.h"

using namespace Zeni;

Tree::Tree(const int &floor_,
           const Point2f &position_,
           const Vector2f &size_)
: Terrain(floor_, position_, size_, true)
{}

void Tree::render() const {
  Game_Object::render("tree");
}

bool Tree::is_cuttable() const {
  return true;
}
