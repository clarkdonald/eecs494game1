//
//  Explorer.h
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#ifndef EXPLORER_H
#define EXPLORER_H

#include "Movable_Object.h"
#include "Utility.h"
#include <Zeni/String.h>
#include <Zeni/Coordinate.h>
#include <list>

class Item;
class Terrain;
class Boulder;

struct Actions {
  Actions();
  void clear();
  void set(const Item &item_);
  bool cut;
  bool fill;
  bool extinguish;
  bool push;
};

class Explorer : public Movable_Object {
  public:
    Explorer(const Position &position_);
  
    ~Explorer();
    
    bool pickup_item(const bool &action_, std::list<Item*> &items_);
  
    bool drop_item(const bool &action_, std::list<Item*> &items_);
  
    bool use_item(const bool &action_,
                  std::list<Boulder*> &boulders_,
                  std::list<Terrain*> &terrains_,
                  const Dimension &dimension_);
  
    bool wielding_item() const;
      
    void render() const;
  
  private:
    Item* m_item;
    Actions m_actions;
};

#endif /* EXPLORER_H */
