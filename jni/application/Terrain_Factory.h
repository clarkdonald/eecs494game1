//
//  Terrain_Factory.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef TERRAIN_FACTORY_H
#define TERRAIN_FACTORY_H

#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Terrain;

Terrain * create_terrain(const Zeni::String &type_,
                         const int &floor_,
                         const Zeni::Point2f &position_,
                         const int &destination_floor_ = 0,
                         const Zeni::Point2f &destination_position_ = Zeni::Point2f(400.0f, 300.0f));

#endif /* TERRAIN_FACTORY_H */
