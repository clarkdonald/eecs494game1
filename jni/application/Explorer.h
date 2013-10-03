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

struct Actions {
  Actions();
  void clear();
  void set(const Item &item_);
  bool cut;
  bool burn;
  bool light;
  bool push;
};

class Explorer : public Movable_Object {
  public:
    Explorer(const int &floor_,
             const Zeni::Point2f &position_,
             const Zeni::Vector2f &size_);
  
    ~Explorer();
    
    void pickup_item(const bool &action_, std::list<Item*> &items_);
  
    void drop_item(const bool &action_, std::list<Item*> &items_);
  
    void use_item(const bool &action_, std::list<Terrain*> &terrains_);
  
    bool wielding_item() const;
  
    const bool & is_sliding() const;
  
    void set_sliding(const bool &sliding_);
  
    void collide(const std::list<Terrain*> &terrains_);
    
    void render() const;
  
  private:
    Item* m_item;
  
    bool m_sliding;
  
    Actions m_actions;
};

#endif /* EXPLORER_H */
