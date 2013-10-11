//
//  Dumbbell.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef DUMBBELL_H
#define DUMBBELL_H

#include "Item.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Dumbbell : public Item {
  public:
    Dumbbell(const Position &position_);
      
    void render() const;
    
    bool for_pushing() const override;
};

#endif /* DUMBBELL_H */
