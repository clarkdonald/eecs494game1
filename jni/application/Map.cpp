//
//  Map.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Map.h"
#include "Terrain.h"
#include "Item.h"
#include "Exit.h"
#include "Ground.h"
#include "Terrain_Factory.h"
#include "Item_Factory.h"
#include <Zeni/Image.h>
#include <Zeni/Video.h>
#include <Zeni/Window.h>
#include <Zeni/String.h>
#include <fstream>

using namespace Zeni;
using std::string;
using std::ifstream;
using std::getline;
using std::map;
using std::bad_exception;

Map::Map(const string &file)
: explorer(nullptr)
{
  ifstream next_file(file);
 
  if (!next_file.is_open()) throw new bad_exception();

  map<char, string> element_mapper;
  element_mapper['.'] = "Ground";
  element_mapper['b'] = "Boulder";
  element_mapper['u'] = "Ladder_Up";
  element_mapper['d'] = "Ladder_Down";
  element_mapper['h'] = "Hole";
  element_mapper['w'] = "Water";
  element_mapper['t'] = "Tree";
  element_mapper['e'] = "Exit";
  element_mapper['f'] = "Fire";
  element_mapper['i'] = "Ice";
  element_mapper['A'] = "Axe";
  element_mapper['P'] = "Pill";
  element_mapper['T'] = "Twig";
  
  if (!(next_file >> dimension.floor)) throw new bad_exception;
  if (!(next_file >> dimension.height)) throw new bad_exception;
  if (!(next_file >> dimension.width)) throw new bad_exception;
  
  string line;
  getline(next_file,line); // waste a newline
  for (int floor = 0; floor < dimension.floor; ++floor) {
    for (int height = 0; getline(next_file,line) && height < dimension.height;) {
      if (line.find('#') != std::string::npos) continue;
      for (int width = 0; width < line.length() && width < dimension.width; ++width) {
        if (line[width] == '.');
        else if (line[width] == 's') {
          if (explorer != nullptr) throw new bad_exception;
          explorer = new Explorer(floor,
                                  Point2f(UNIT_LENGTH*width, UNIT_LENGTH*height));
        }
        else if (line[width] == 'e') {
          exits.push_back(new Exit(floor,
                          Point2f(UNIT_LENGTH*width, UNIT_LENGTH*height)));
        }
        else if (isupper(line[width])) {
          map<char,string>::iterator it;
          if ((it = element_mapper.find(line[width])) == element_mapper.end())
            throw new bad_exception;
          items.push_back(
            create_item(String(it->second),
                        floor,
                        Point2f(UNIT_LENGTH*width, UNIT_LENGTH*height)));
        }
        else if (islower(line[width])) {
          map<char,string>::iterator it;
          if ((it = element_mapper.find(line[width])) == element_mapper.end())
            throw new bad_exception;
          terrains.push_back(
            create_terrain(String(it->second),
                           floor,
                           Point2f(UNIT_LENGTH*width, UNIT_LENGTH*height)));
        }
        else {
          throw new bad_exception;
        }
        grounds.push_back(new Ground(floor,
                                     Point2f(UNIT_LENGTH*width, UNIT_LENGTH*height)));
      }
      ++height;
    }
  }
  
  if (explorer == nullptr || exits.empty()) throw new bad_exception;
  next_file.close();
}

Map::~Map() {
  for (auto it = terrains.begin(); it != terrains.end(); ++it) delete *it;
  for (auto it = items.begin(); it != items.end(); ++it) delete *it;
  for (auto it = exits.begin(); it != exits.end(); ++it) delete *it;
  delete explorer;
}

void Map::render() {
  get_Video().set_2d(std::make_pair(explorer->get_position() - Vector2f(300.0f, 200.0f),
                                    explorer->get_position() + Vector2f(500.0f, 400.0f)), true);
  for (auto it = grounds.begin(); it != grounds.end(); ++it)
    if (explorer->get_floor() == (*it)->get_floor()) (*it)->render();
  for (auto it = terrains.begin(); it != terrains.end(); ++it)
    if (explorer->get_floor() == (*it)->get_floor()) (*it)->render();
  for (auto it = items.begin(); it != items.end(); ++it)
    if (explorer->get_floor() == (*it)->get_floor()) (*it)->render();
  for (auto it = exits.begin(); it != exits.end(); ++it)
    if (explorer->get_floor() == (*it)->get_floor()) (*it)->render();
  explorer->render();
}

bool Map::perform_logic(Controls &controls_, const float &time_step_) {
  explorer->face(controls_.right - controls_.left, controls_.down - controls_.up);
  
  for (auto it = terrains.begin(); it != terrains.end(); ++it) {
    if (explorer->touching(**it) && (*it)->is_blocking()) {
      const Vector2f dist_vec = explorer->get_position() - (*it)->get_position()
      + 0.5f * (explorer->get_size() - (*it)->get_size());
      if (abs(dist_vec.x) > abs(dist_vec.y)) {
        if (dist_vec.x > 0.0f) controls_.left = false;
        else controls_.right = false;
      }
      else {
        if (dist_vec.y > 0.0f) controls_.up = false;
        else controls_.down = false;
      }
    }
  }
  
  if (explorer->get_position().x <= 0.0f)
    controls_.left = false;
  if (explorer->get_position().x >= (dimension.width*UNIT_LENGTH - UNIT_LENGTH))
    controls_.right = false;
  if (explorer->get_position().y <= 0.0f)
    controls_.up = false;
  if (explorer->get_position().y >= (dimension.height*UNIT_LENGTH - UNIT_LENGTH))
    controls_.down = false;
  
  if (!explorer->is_sliding()) {
    float multiplier = time_step_ * (controls_.speed_boost ? 150.0f : 100.0f);
    explorer->move((controls_.right - controls_.left) * multiplier,
                    (controls_.down - controls_.up) * multiplier);
  }
  
  for (auto it = exits.begin(); it != exits.end(); ++it)
    if ((*it)->touching(*explorer))
      return true;
  
  explorer->collide(terrains);
  explorer->pickup_item(controls_.pickup, items);
  explorer->drop_item(controls_.drop, items);
  explorer->use_item(controls_.use, terrains);
  
  return false;
}

