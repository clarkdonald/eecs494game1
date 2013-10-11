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
#include <list>

class Terrain;
class Boulder;

struct Sliding {
  Sliding();
  bool is_sliding;
  Direction direction;
};

class Movable_Object : public Game_Object {
  public:
    Movable_Object(const Position &position_,
                   const Direction &direction_);
    
    const Direction & get_direction() const;
  
    const bool & is_sliding() const;
  
    const Direction & get_sliding_direction() const;
  
    void reset_sliding();
  
    void set_sliding(const Direction & direction_);
  
    void face(const float &horizontal_, const float &vertical_);
  
    void move(float horizontal_,
              float vertical_,
              const std::list<Boulder*> &boulders,
              const std::list<Terrain*> &terrains,
              const Dimension &dimension);
  
  private:
    Direction direction;
    Sliding sliding;
};

#endif /* MOVABLE_OBJECT_H */
