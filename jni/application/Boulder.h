//
//  Boulder.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef BOULDER_H
#define BOULDER_H

#include "Terrain.h"
#include "Explorer.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Boulder : public Terrain {
  public:
    Boulder(const int &floor_,
            const Zeni::Point2f &position_,
            const Zeni::Vector2f &size_);
    
    void render() const;
      
    bool is_pushable() const override;
};

#endif /* BOULDER_H */