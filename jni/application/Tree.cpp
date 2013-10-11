//
//  Tree.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Tree.h"

using namespace Zeni;

Tree::Tree(const Position &position_)
: Terrain(position_)
{}

void Tree::render() const {
  Game_Object::render("tree");
}

bool Tree::is_movable_blocking() const {
  return true;
}

bool Tree::is_terrain_blocking() const {
  return true;
}

bool Tree::is_cuttable() const {
  return true;
}
