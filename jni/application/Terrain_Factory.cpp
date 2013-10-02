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
                         const Point2f &position_,
                         const Vector2f &size_,
                         const Point2f &destination_)
{
  if (type_ == "Boulder") {
    return new Boulder(position_, size_);
  }
  else if (type_ == "Ladder_Up") {
    return new Ladder_Up(position_, size_);
  }
  else if (type_ == "Ladder_Down") {
    return new Ladder_Down(position_, size_);
  }
  else if (type_ == "Hole") {
    return new Hole(position_, size_);
  }
  else if (type_ == "Water") {
    return new Water(position_, size_);
  }
  else if (type_ == "Tree") {
    return new Tree(position_, size_);
  }
  else if (type_ == "Exit") {
    return new Exit(position_, size_);
  }
  else if (type_ == "Teleport") {
    return new Teleport(position_, size_, destination_);
  }
  else if (type_ == "Fire") {
    return new Fire(position_, size_);
  }
  else if (type_ == "Ice") {
    return new Ice(position_, size_);
  }
  else {
    throw new std::bad_alloc;
  }
}
