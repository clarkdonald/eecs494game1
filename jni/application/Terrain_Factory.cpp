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
                         const int &floor_,
                         const Point2f &position_,
                         const int &destination_floor_,
                         const Point2f &destination_position_)
{
  if (type_ == "Boulder") {
    return new Boulder(floor_, position_);
  }
  else if (type_ == "Ladder_Up") {
    return new Ladder_Up(floor_, position_);
  }
  else if (type_ == "Ladder_Down") {
    return new Ladder_Down(floor_, position_);
  }
  else if (type_ == "Hole") {
    return new Hole(floor_, position_);
  }
  else if (type_ == "Water") {
    return new Water(floor_, position_);
  }
  else if (type_ == "Tree") {
    return new Tree(floor_, position_);
  }
  else if (type_ == "Exit") {
    return new Exit(floor_, position_);
  }
  else if (type_ == "Portal") {
    return new Portal(floor_, position_, destination_floor_, destination_position_);
  }
  else if (type_ == "Fire") {
    return new Fire(floor_, position_);
  }
  else if (type_ == "Ice") {
    return new Ice(floor_, position_);
  }
  else if (type_ == "Ground") {
    return new Ground(floor_, position_);
  }
  else {
    throw new std::bad_alloc;
  }
}
