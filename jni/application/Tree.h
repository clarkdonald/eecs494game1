//
//  Tree.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef TREE_H
#define TREE_H

#include "Terrain.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Tree : public Terrain {
  public:
    Tree(const Position &position_);
    
    void render() const;
  
    bool is_movable_blocking() const override;
  
    bool is_terrain_blocking() const override;
  
    bool is_cuttable() const override;
};

#endif /* TREE_H */
