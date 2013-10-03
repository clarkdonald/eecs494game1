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
#include "Explorer.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>

class Tree : public Terrain {
  public:
    Tree(const int &floor_,
         const Zeni::Point2f &position_,
         const Zeni::Vector2f &size_);
    
    void render() const;
      
    bool is_cuttable() const override;
};

#endif /* TREE_H */
