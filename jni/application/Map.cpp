//
//  Map.cpp
//  game
//
//  Created by Donald Clark on 9/27/13.
//
//

#include "Map.h"
#include "Explorer.h"
#include "Terrain.h"
#include "Item.h"
#include "Boulder.h"
#include "Exit.h"
#include "Ground.h"
#include <Zeni/Image.h>
#include <Zeni/Video.h>
#include <Zeni/Window.h>
#include <Zeni/String.h>

using namespace Zeni;
using std::string;

Map::Map()
: explorer(nullptr)
{}

Map::~Map() {
  for (auto it = terrains.begin(); it != terrains.end(); ++it) delete *it;
  for (auto it = items.begin(); it != items.end(); ++it) delete *it;
  for (auto it = exits.begin(); it != exits.end(); ++it) delete *it;
  for (auto it = boulders.begin(); it != boulders.end(); ++it) delete *it;
  delete explorer;
}

const Point2f & Map::get_explorer_position() const {
  return explorer->get_position().position;
}

string Map::get_level_info() const {
  return level_info;
}

void Map::render() {
  for (auto it = grounds.begin(); it != grounds.end(); ++it)
    if (explorer->get_position().floor == (*it)->get_position().floor) (*it)->render();
  for (auto it = terrains.begin(); it != terrains.end(); ++it)
    if (explorer->get_position().floor == (*it)->get_position().floor) (*it)->render();
  for (auto it = items.begin(); it != items.end(); ++it)
    if (explorer->get_position().floor == (*it)->get_position().floor) (*it)->render();
  for (auto it = exits.begin(); it != exits.end(); ++it)
    if (explorer->get_position().floor == (*it)->get_position().floor) (*it)->render();
  for (auto it = boulders.begin(); it != boulders.end(); ++it)
    if (explorer->get_position().floor == (*it)->get_position().floor) (*it)->render();
  explorer->render();
}

Status Map::perform_logic(Controls &controls_, const float &time_step_) {
  for (auto it = exits.begin(); it != exits.end(); ++it)
    if ((*it)->touching(*explorer))
      return DONE;
    
  explorer->face(controls_.right - controls_.left, controls_.down - controls_.up);
  
  float multiplier = time_step_ * (controls_.speed_boost ? 150.0f : 100.0f);
  explorer->move((controls_.right - controls_.left) * multiplier,
                 (controls_.down - controls_.up) * multiplier,
                 boulders,
                 terrains,
                 dimension);
  
  if (!pickup_timer.is_running()) {
    if (explorer->pickup_item(controls_.pickup, items)) {
      pickup_timer.reset();
      pickup_timer.start();
    }
  }
  else {
    if (pickup_timer.seconds() > 0.3f) pickup_timer.stop();
  }
  
  if (!drop_timer.is_running()) {
    if (explorer->drop_item(controls_.drop, items)) {
      drop_timer.reset();
      drop_timer.start();
    }
  }
  else {
    if (drop_timer.seconds() > 0.3f) drop_timer.stop();
  }

  if (!use_timer.is_running()) {
    if (explorer->use_item(controls_.use, boulders, terrains, dimension)) {
      use_timer.reset();
      use_timer.start();
    }
  }
  else {
    if (use_timer.seconds() > 0.3f) use_timer.stop();
  }
  
  return UNDONE;
}
