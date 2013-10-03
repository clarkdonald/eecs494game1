//
//  Pill.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef PILL_H
#define PILL_H

#include "Item.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Pill : public Item {
  public:
    Pill(const int &floor_,
         const Zeni::Point2f &position_,
         const Zeni::Vector2f &size_);
      
    void render() const;
    
    bool for_pushing() const override;
};

#endif /* PILL_H */
