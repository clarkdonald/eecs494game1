//
//  Axe.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef AXE_H
#define AXE_H

#include "Item.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Axe : public Item {
  public:
    Axe(const Position &position_);
    
    void render() const;
    
    bool for_cutting() const override;
};

#endif /* AXE_H */
