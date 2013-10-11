//
//  Water.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef WATER_H
#define WATER_H

#include "Terrain.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Water : public Terrain {
public:
  Water(const Position &position_);
  
  void render() const;
  
  bool is_movable_blocking() const override;
  
  bool is_water_filling() const override;
  
  bool is_crushable() const override;
};

#endif /* WATER_H */
