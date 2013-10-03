//
//  Utility.cpp
//  game
//
//  Created by Donald Clark on 10/2/13.
//
//

#include "Utility.h"

Controls::Controls()
: up(false),
  left(false),
  down(false),
  right(false),
  speed_boost(false),
  pickup(false),
  drop(false),
  use(false)
{}

Dimension::Dimension()
: width(0),
  height(0),
  floor(0)
{}

Dimension::Dimension(int width_, int height_, int floor_)
: width(width_),
  height(height_),
  floor(floor_)
{}
