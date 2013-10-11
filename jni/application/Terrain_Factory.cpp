//
//  Terrain_Factory.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Terrain_Factory.h"
#include "Terrain_Includes.h"

using std::bad_alloc;
using namespace Zeni;

Terrain * create_terrain(const String &type_,
                         const Position &position_,
                         const Position &destination_position_)
{
  if (type_ == "Boulder") return new Boulder(position_);
  else if (type_ == "Ladder_Up") return new Ladder_Up(position_);
  else if (type_ == "Ladder_Down") return new Ladder_Down(position_);
  else if (type_ == "Hole") return new Hole(position_);
  else if (type_ == "Water") return new Water(position_);
  else if (type_ == "Tree") return new Tree(position_);
  else if (type_ == "Exit") return new Exit(position_);
  else if (type_ == "Portal") return new Portal(position_, destination_position_);
  else if (type_ == "Fire") return new Fire(position_);
  else if (type_ == "Ice") return new Ice(position_);
  else if (type_ == "Ground") return new Ground(position_);
  else if (type_ == "Skip") return new Skip(position_);
  else throw new std::bad_alloc;
}
