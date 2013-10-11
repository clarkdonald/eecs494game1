//
//  Skip.h
//  game
//
//  Created by Donald Clark on 10/10/13.
//
//

#ifndef SKIP_H
#define SKIP_H

#include "Terrain.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Skip : public Terrain {
public:
  Skip(const Position &position_);
  
  void render() const;
};

#endif /* SKIP_H */
