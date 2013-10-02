//
//  Movable_Object.h
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#ifndef MOVABLE_OBJECT_H
#define MOVABLE_OBJECT_H

#include "Game_Object.h"
#include "Utility.h"
#include <Zeni/Coordinate.h>

class Movable_Object : public Game_Object {
  public:
    Movable_Object(const Zeni::Point2f &position_,
                   const Zeni::Vector2f &size_,
                   const Direction &direction_,
                   const bool &blocking_,
                   const float &speed_ = 0.0f);
    
    const Direction & get_direction() const;
  
    void face(const float &horizontal_, const float &vertical_);
  
    void move(const float &horizontal_, const float &vertical_);
  
  private:
    Direction m_direction;
};

#endif /* MOVABLE_OBJECT_H */
