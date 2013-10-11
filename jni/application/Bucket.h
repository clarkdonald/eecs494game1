//
//  Bucket.h
//  game
//
//  Created by Donald Clark on 10/2/13.
//
//

#ifndef BUCKET_H
#define BUCKET_H

#include "Item.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Bucket : public Item {
  public:
    Bucket(const Position &position_);
    
    void render() const;
    
  virtual bool for_extinguishing() const override;
  
  virtual bool for_water_filling() const override;
};

#endif /* BUCKET_H */
