//
//  Map_Manager.h
//  game
//
//  Created by Donald Clark on 10/2/13.
//
//

#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H

#include <vector>
#include <map>
#include <string>

class Map;

const int NUM_FILES = 1;

class Map_Manager {
  public:
    static Map_Manager& get_Instance();
  
    // forbid copy/move, construction/assignment
    Map_Manager(const Map_Manager&) = delete;
    Map_Manager(Map_Manager&&) = delete;
    Map_Manager& operator= (const Map_Manager&) = delete;
    Map_Manager& operator= (Map_Manager&&) = delete;
    
    const int & get_files_left() const;
  
    bool empty() const;
  
    void reset();
  
    Map* get_next();
  
    Map* get(const std::string &file);
  
  private:
    Map_Manager();
  
    int index;
    std::vector<std::string> files;
};

#endif /* MAP_MANAGER_H */
