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
#include "Explorer.h"
#include <Zeni/Coordinate.h>
#include <string>
#include <map>

class Item;
class Terrain;
class Game_Object;
class Exit;
class Ground;

class Map {
  public:
    // constructor
    Map(const std::string &file);
  
    // destructor
    ~Map();
  
    // forbid copy/move, construction/assignment
    Map(const Map&) = delete;
    Map(Map&&) = delete;
    Map& operator= (const Map&) = delete;
    Map& operator= (Map&&) = delete;
  
    void render();
  
    bool perform_logic(Controls &controls_, const float &time_step_);
  
  private:
    //static std::map<char, std::string> element_mapper;
    Dimension dimension;
    std::list<Ground*> grounds;
    std::list<Item*> items;
    std::list<Terrain*> terrains;
    std::list<Exit*> exits;
    Explorer *explorer;
    std::vector< std::vector<Game_Object*> > grid;
};

#endif /* MAP_H */
