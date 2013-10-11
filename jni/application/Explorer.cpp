//
//  Explorer.cpp
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#include "Explorer.h"
#include "Item.h"
#include "Terrain.h"
#include "Boulder.h"
#include <algorithm>

using namespace Zeni;
using std::swap;
using std::list;
using std::bad_exception;

Actions::Actions()
: cut(false), fill(false), extinguish(false), push(false)
{}

void Actions::clear() {
  cut = fill = extinguish = push = false;
}

void Actions::set(const Item &item_) {
  cut = item_.for_cutting();
  fill = item_.for_water_filling();
  push = item_.for_pushing();
}

Explorer::Explorer(const Position &position_)
: Movable_Object(position_, DOWN),
  m_item(nullptr)
{}

Explorer::~Explorer() {
  if (wielding_item()) delete m_item;
}

bool Explorer::pickup_item(const bool &action_, list<Item*> &items_) {
  if (action_) {
    for (auto it = items_.begin(); it != items_.end(); ++it) {
      if ((*it)->touching(*this)) {
        if (wielding_item()) {
          m_actions.clear();
          m_item->set_position(Game_Object::get_position());
          swap(*it, m_item);
        }
        else {
          m_item = *it;
          items_.erase(it);
        }
        m_actions.set(*m_item);
        return true;
      }
    }
  }
  return false;
}

bool Explorer::drop_item(const bool &action_, list<Item*> &items_) {
  if (action_ && wielding_item()) {
    m_actions.clear();
    m_item->set_position(Game_Object::get_position());
    items_.push_back(m_item);
    m_item = nullptr;
    return true;
  }
  return false;
}

bool dfsCollisionCheck(Boulder* boulder,
                       const Position& next,
                       const Position& original,
                       list<Boulder*> &boulders,
                       list<Terrain*> &terrains)
{
  boulder->set_position(next);
  list<list<Terrain*>::iterator> kill;
  for (auto it = terrains.begin(); it != terrains.end(); ++it) {
    if (boulder->touching(**it)) {
      if ((*it)->is_crushable()) {
        kill.push_back(it);
      }
      else if ((*it)->is_droppable()) {
        Position next = boulder->get_position();
        next.floor -= 1;
        return dfsCollisionCheck(boulder, next, original, boulders, terrains);
      }
      else if ((*it)->is_terrain_blocking()) {
        boulder->set_position(original);
        return false;
      }
    }
  }
  for (auto it = boulders.begin(); it != boulders.end(); ++it) {
    if (*it == boulder) continue;
    
    if (boulder->touching(**it)) {
      boulder->set_position(original);
      return false;
    }
  }
  while (!kill.empty()) {
    terrains.erase(kill.front());
    kill.pop_front();
    return true;
  }
  return false;
}

bool Explorer::use_item(const bool &action_,
                        list<Boulder*> &boulders_,
                        list<Terrain*> &terrains_,
                        const Dimension &dimension_)
{
  if (action_ && wielding_item()) {
    if (m_actions.cut) {
      for (auto it = terrains_.begin(); it != terrains_.end(); ++it) {
        if ((*it)->is_cuttable() && (*it)->pseudo_touching(*this)) {
          switch (get_direction()) {
            case UP:
              if (get_position().position.y > (*it)->get_position().position.y) {
                 terrains_.erase(it);
                 return true;
              }
              break;
              
            case DOWN:
              if (get_position().position.y < (*it)->get_position().position.y) {
                terrains_.erase(it);
                return true;
              }
              break;
              
            case LEFT:
              if (get_position().position.x > (*it)->get_position().position.x) {
                terrains_.erase(it);
                return true;
              }
              break;
              
            case RIGHT:
              if (get_position().position.x < (*it)->get_position().position.x) {
                terrains_.erase(it);
                return true;
              }
              break;
              
            default:
              break;
          }
        }
      }
    }
    if (!m_actions.extinguish && m_actions.fill) {
      for (auto it = terrains_.begin(); it != terrains_.end(); ++it) {
        if ((*it)->is_water_filling() && (*it)->pseudo_touching(*this)) {
          switch (get_direction()) {
            case UP:
              if (get_position().position.y > (*it)->get_position().position.y) {
                m_actions.extinguish = true;
                return true;
              }
              break;
              
            case DOWN:
              if (get_position().position.y < (*it)->get_position().position.y) {
                m_actions.extinguish = true;
                return true;
              }
              break;
              
            case LEFT:
              if (get_position().position.x > (*it)->get_position().position.x) {
                m_actions.extinguish = true;
                return true;
              }
              break;
              
            case RIGHT:
              if (get_position().position.x < (*it)->get_position().position.x) {
                m_actions.extinguish = true;
                return true;
              }
              break;
              
            default:
              break;
          }
        }
      }
    }
    if (m_actions.extinguish) {
      for (auto it = terrains_.begin(); it != terrains_.end(); ++it) {
        if ((*it)->is_extinguishable() && (*it)->pseudo_touching(*this)) {
          switch (get_direction()) {
            case UP:
              if (get_position().position.y > (*it)->get_position().position.y) {
                terrains_.erase(it);
                return true;
              }
              break;
              
            case DOWN:
              if (get_position().position.y < (*it)->get_position().position.y) {
                terrains_.erase(it);
                return true;
              }
              break;
              
            case LEFT:
              if (get_position().position.x > (*it)->get_position().position.x) {
                terrains_.erase(it);
                return true;
              }
              break;
              
            case RIGHT:
              if (get_position().position.x < (*it)->get_position().position.x) {
                terrains_.erase(it);
                return true;
              }
              break;
              
            default:
              break;
          }
        }
      }
    }
    if (m_actions.push) {
      for (auto it = boulders_.begin(); it != boulders_.end(); ++it) {
        if ((*it)->pseudo_touching(*this)) {
          Position original = (*it)->get_position();
          Position next = (*it)->get_position();
          switch (get_direction()) {
            case UP:
              if (get_position().position.y < (*it)->get_position().position.y)
                continue;
              next.position.y -= UNIT_LENGTH;
              break;
              
            case DOWN:
              if (get_position().position.y > (*it)->get_position().position.y)
                continue;
              next.position.y += UNIT_LENGTH;
              break;
              
            case LEFT:
              if (get_position().position.x < (*it)->get_position().position.x)
                continue;
              next.position.x -= UNIT_LENGTH;
              break;
              
            case RIGHT:
              if (get_position().position.x > (*it)->get_position().position.x)
                continue;
              next.position.x += UNIT_LENGTH;
              break;
              
            default:
              break;
          }
          
          if (next.position.x < 0.0f ||
              next.position.x > (dimension_.width*UNIT_LENGTH - UNIT_LENGTH) ||
              next.position.y < 0.0f ||
              next.position.y > (dimension_.height*UNIT_LENGTH - UNIT_LENGTH))
          {
            continue;
          }
          
          if (dfsCollisionCheck(*it, next, original, boulders_, terrains_))
            boulders_.erase(it);
          return true;
        }
      }
    }
  }
  return false;
}

bool Explorer::wielding_item() const {
  return m_item != nullptr;
}

void Explorer::render() const {
  switch(Movable_Object::get_direction()) {
    case UP:
      Game_Object::render("explorer_u");
      break;
      
    case DOWN:
      Game_Object::render("explorer_d");
      break;
      
    case LEFT:
      Game_Object::render("explorer_l");
      break;
      
    case RIGHT:
      Game_Object::render("explorer_r");
      break;
      
    default:
      throw new bad_exception;
      break;
  }
}
