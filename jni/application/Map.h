//
//  Map.h
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#ifndef MAP_H
#define MAP_H

#include <list>
#include "Utility.h"
#include <Zeni/Coordinate.h>
#include <Zeni/Widget.h>
#include <Zeni/Joysticks.h>
#include <Zeni/Game.hxx>
#include <Zeni/Timer.h>
#include <Zeni/Chronometer.h>
#include <string>
#include <map>

class Item;
class Terrain;
class Game_Object;
class Boulder;
class Exit;
class Ground;
class Explorer;

enum Status { DONE, UNDONE, SKIP };

class Map {
  public:
    // constructor
    Map();
  
    // destructor
    virtual ~Map() = 0;
  
    // forbid copy/move, construction/assignment
    Map(const Map&) = delete;
    Map(Map&&) = delete;
    Map& operator= (const Map&) = delete;
    Map& operator= (Map&&) = delete;
  
    // get explorer coordinate
    const Zeni::Point2f & get_explorer_position() const;
  
    // return level info
    std::string get_level_info() const;

    // show game objects on screen
    virtual void render();
  
    // perform logical operations of game object based on user input
    virtual Status perform_logic(Controls &controls_, const float &time_step_);
  
  protected:
    Dimension dimension;
    std::list<Boulder*> boulders;
    std::list<Ground*> grounds;
    std::list<Item*> items;
    std::list<Terrain*> terrains;
    std::list<Exit*> exits;
    Explorer *explorer;
    std::string level_info;
    Zeni::Chronometer<Zeni::Time> use_timer;
    Zeni::Chronometer<Zeni::Time> drop_timer;
    Zeni::Chronometer<Zeni::Time> pickup_timer;
};

#endif /* MAP_H */
