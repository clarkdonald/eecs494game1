//
//  Twig.h
//  game
//
//  Created by Donald Clark on 10/2/13.
//
//

#ifndef TWIG_H
#define TWIG_H

#include "Item.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Twig : public Item {
  public:
    Twig(const int &floor_,
         const Zeni::Point2f &position_,
         const Zeni::Vector2f &size_);
    
    void render() const;
    
    virtual bool for_burning() const;
    
    virtual bool for_lighting() const;
};

#endif /* TWIG_H */
