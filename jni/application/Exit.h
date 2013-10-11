//
//  Exit.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef EXIT_H
#define EXIT_H

#include "Terrain.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Exit : public Terrain {
  public:
    Exit(const Position &position_);
    
    void render() const;
};

#endif /* EXIT_H */
