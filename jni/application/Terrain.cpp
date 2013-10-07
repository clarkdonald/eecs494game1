//
//  Terrain.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Terrain.h"

Terrain::Terrain(const int &floor_,
                 const Zeni::Point2f &position_,
                 const bool &blocking_)
: Game_Object(floor_, position_, blocking_)
{}

Terrain::~Terrain() {}

void Terrain::interact(Explorer &explorer) {
  // default behavior: do nothing
}

bool Terrain::is_cuttable() const {
  return false;
}

bool Terrain::is_burnable() const {
  return false;
}

bool Terrain::is_pushable() const {
  return false;
}

bool Terrain::is_crushable() const {
  return false;
}
