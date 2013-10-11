//
//  Terrain.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Terrain.h"

Terrain::Terrain(const Position &position_)
: Game_Object(position_)
{}

Terrain::~Terrain() {}

void Terrain::interact(Movable_Object &object_) {
  // default behavior: do nothing
}

bool Terrain::is_movable_blocking() const {
  return false;
}

bool Terrain::is_terrain_blocking() const {
  return false;
}

bool Terrain::is_droppable() const {
  return false;
}

bool Terrain::is_cuttable() const {
  return false;
}

bool Terrain::is_water_filling() const {
  return false;
}

bool Terrain::is_extinguishable() const {
  return false;
}

bool Terrain::is_crushable() const {
  return false;
}

bool Terrain::is_forced_move() const {
  return false;
}
