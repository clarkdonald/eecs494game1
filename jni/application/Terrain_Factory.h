//
//  Terrain_Factory.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef TERRAIN_FACTORY_H
#define TERRAIN_FACTORY_H

#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Terrain;

Terrain * create_terrain(const Zeni::String &type_,
                         const Position &position_,
                         const Position &destination_position_ = Position(0, Zeni::Point2f(400.0f, 300.0f)));

#endif /* TERRAIN_FACTORY_H */
