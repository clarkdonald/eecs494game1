//
//  PlayMap.cpp
//  game
//
//  Created by Donald Clark on 10/10/13.
//
//

#include "PlayMap.h"
#include "Terrain.h"
#include "Item.h"
#include "Boulder.h"
#include "Exit.h"
#include "Ground.h"
#include "Skip.h"
#include "Terrain_Factory.h"
#include "Item_Factory.h"
#include <Zeni/Image.h>
#include <Zeni/Video.h>
#include <Zeni/Window.h>
#include <Zeni/String.h>
#include <fstream>

using namespace Zeni;
using std::map;
using std::getline;
using std::string;
using std::ifstream;
using std::bad_exception;
using std::to_string;

PlayMap::PlayMap(const std::string &file)
: Map()
{
  ifstream next_file(file);
  
  if (!next_file.is_open()) throw new bad_exception();
  
  floor_text = new Text_Box(Point2f(), Point2f(800.0f, 600.0f), "title", "", Color());
  floor_text->give_BG_Renderer(new Widget_Renderer_Color(get_Colors()["black"]));
  
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
  element_mapper['D'] = "Dumbbell";
  element_mapper['B'] = "Bucket";
  
  if (!(next_file >> dimension.floor)) throw new bad_exception;
  if (!(next_file >> dimension.height)) throw new bad_exception;
  if (!(next_file >> dimension.width)) throw new bad_exception;
  
  string line;
  getline(next_file,line); // waste a newline
  for (int floor = 0; floor < dimension.floor; ++floor) {
    for (int height = 0; getline(next_file,line) && height < dimension.height;) {
      if (line.find('#') != std::string::npos) continue;
      for (int width = 0; width < line.length() && width < dimension.width; ++width) {
        Position position(floor,Point2f(UNIT_LENGTH*width, UNIT_LENGTH*height));
        if (line[width] == '.');
        else if (line[width] == 's') {
          if (explorer != nullptr) throw new bad_exception;
          explorer = new Explorer(position);
        }
        else if (line[width] == 'e') {
          exits.push_back(new Exit(position));
        }
        else if (line[width] == 'b') {
          boulders.push_back(new Boulder(position));
        }
        else if (line[width] == 'E') {
          boulders.push_back(new Boulder(position));
          exits.push_back(new Exit(position));
        }
        else if (line[width] == 'a') {
          boulders.push_back(new Boulder(position));
          items.push_back(create_item("Axe", position));
        }
        else if (line[width] == 'm') {
          boulders.push_back(new Boulder(position));
          items.push_back(create_item("Bucket", position));
        }
        else if (isupper(line[width])) {
          map<char,string>::iterator it;
          if ((it = element_mapper.find(line[width])) == element_mapper.end())
            throw new bad_exception;
          items.push_back(create_item(String(it->second),position));
        }
        else if (islower(line[width])) {
          map<char,string>::iterator it;
          if ((it = element_mapper.find(line[width])) == element_mapper.end())
            throw new bad_exception;
          terrains.push_back(create_terrain(String(it->second),position));
        }
        else {
          throw new bad_exception;
        }
        grounds.push_back(new Ground(position));
      }
      ++height;
    }
  }
  
  if (explorer == nullptr || exits.empty()) throw new bad_exception;
  
  level_info = "\n\n\t\t  Level ";
  int first, last;
  for (first = 0; first < file.length(); ++first) if (isdigit(file[first])) break;
  for (last = first + 1; last < file.length(); ++last) if (!isdigit(file[last])) break;
  level_info += file.substr(first,last-first);
  level_info += "\n\t\t  Floors: ";
  level_info += to_string(dimension.floor);
  
  next_file.close();
}

PlayMap::~PlayMap() {}

// show game objects on screen
void PlayMap::render() {
  if (floor_change.is_running()) {
    if (floor_change.seconds() < 1.0f) {
      floor_text->render();
    }
    else {
      floor_change.stop();
    }
  }
  else {
    get_Video().set_2d(std::make_pair(explorer->get_position().position - Vector2f(300.0f, 200.0f),
                                      explorer->get_position().position + Vector2f(500.0f, 400.0f)), true);
    Map::render();
  }
}

// perform logical operations of game object based on user input
Status PlayMap::perform_logic(Controls &controls_, const float &time_step_) {
  if (!floor_change.is_running()) {
    Position pos = explorer->get_position();
    Status status = Map::perform_logic(controls_, time_step_);
    if (status == DONE) return status;
    if (pos.floor != explorer->get_position().floor) {
      floor_change.reset();
      floor_change.start();
      floor_text->set_upper_left(explorer->get_position().position - Vector2f(300.0f, 200.0f));
      floor_text->set_lower_right(explorer->get_position().position + Vector2f(500.0f, 400.0f));
      floor_text->set_text(String("\n\n\t\t  Floor " + to_string(explorer->get_position().floor + 1)));
    }
  }
  return UNDONE;
}
