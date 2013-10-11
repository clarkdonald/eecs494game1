//
//  TutorialMap.cpp
//  game
//
//  Created by Donald Clark on 10/10/13.
//
//

#include "TutorialMap.h"
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
using std::string;
using std::getline;
using std::map;
using std::ifstream;
using std::bad_exception;
using std::make_pair;

String level0 = "You are an explorer trying to get to your airplane."
  " Your airplane looks like the game piece located to your right.\n\n"
  "If you want to skip to normal game play during the tutorial, go to an"
  " icon that looks like the game piece located to your left.";

String level1 = "There are items located above you and terrains located below you.\n\n"
  "Items can be picked up, dropped, and used on terrains. You can only carry one item at a time.\n\n"
  "Terrains either block your movement as an obstruction or force movement upon you.\n\n";

String level2 = "Above you is a dumb-bell. Once picked up, you can push boulders like the one located below you.\n\n"
  "Boulders can be pushed into water to enable movement over them, or they can be dropped down holes.";

String level3 = "Above you is an axe.  Once picked up, you can cut down trees.";

String level4 = "Above you is a bucket.  Once picked up, you can fill them with water and "
  "extinguish fire.";

TutorialMap::TutorialMap(const string &file)
: Map(),
  skip(nullptr)
{
  ifstream next_file(file);
  
  if (!next_file.is_open()) throw new bad_exception();
  
  if (file.find("0") != std::string::npos)
    tb = new Text_Box(Point2f(0.0f, 300.0f), Point2f(800.0f, 600.0f), "system_36_800x600", level0, Color());
  else if (file.find("1") != std::string::npos)
    tb = new Text_Box(Point2f(0.0f, 300.0f), Point2f(800.0f, 600.0f), "system_36_800x600", level1, Color());
  else if (file.find("2") != std::string::npos)
    tb = new Text_Box(Point2f(0.0f, 300.0f), Point2f(800.0f, 600.0f), "system_36_800x600", level2, Color());
  else if (file.find("3") != std::string::npos)
    tb = new Text_Box(Point2f(0.0f, 300.0f), Point2f(800.0f, 600.0f), "system_36_800x600", level3, Color());
  else if (file.find("4") != std::string::npos)
    tb = new Text_Box(Point2f(0.0f, 300.0f), Point2f(800.0f, 600.0f), "system_36_800x600", level4, Color());
  
  tb->give_BG_Renderer(new Widget_Renderer_Color(get_Colors()["black"]));
  
  map<char, string> element_mapper;
  element_mapper['.'] = "Ground";
  element_mapper['n'] = "Skip";
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
        else if (line[width] == 'n') {
          skip = new Skip(position);
        }
        else if (line[width] == 'b') {
          boulders.push_back(new Boulder(position));
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
  level_info = "";
  next_file.close();
}

TutorialMap::~TutorialMap() {
  delete skip;
}

// show game objects on screen
void TutorialMap::render() {
  get_Video().set_2d(make_pair(Point2f(), Point2f(800.0f, 600.0f)), true);
  tb->render();
  Map::render();
  skip->render();
}

// perform logical operations of game object based on user input
Status TutorialMap::perform_logic(Controls &controls_, const float &time_step_) {
  if (skip->touching(*explorer)) return SKIP;
  return Map::perform_logic(controls_, time_step_);
}
