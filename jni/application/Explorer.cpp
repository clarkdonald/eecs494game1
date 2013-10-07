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
#include <algorithm>

using namespace Zeni;
using std::swap;
using std::list;
using std::bad_exception;

Actions::Actions()
: cut(false), burn(false), light(false), push(false)
{}

void Actions::clear() {
  cut = burn = light = push = false;
}

void Actions::set(const Item &item_) {
  cut = item_.for_cutting();
  burn = item_.for_burning();
  push = item_.for_pushing();
  light = item_.for_lighting();
}

Explorer::Explorer(const int &floor_, const Point2f &position_)
: Movable_Object(floor_, position_, DOWN, true),
  m_item(nullptr),
  m_sliding(false)
{}

Explorer::~Explorer() {
  if (wielding_item()) {
    delete m_item;
  }
}

void Explorer::pickup_item(const bool &action_, list<Item*> &items_) {
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
        break;
      }
    }
  }
}

void Explorer::drop_item(const bool &action_, std::list<Item*> &items_) {
  if (action_ && wielding_item()) {
    m_actions.clear();
    m_item->set_position(Game_Object::get_position());
    m_item->set_floor(Game_Object::get_floor());
    items_.push_back(m_item);
    m_item = nullptr;
  }
}

void Explorer::use_item(const bool &action_, list<Terrain*> &terrains_) {
  if (action_ && wielding_item()) {
    for (auto it = terrains_.begin(); it != terrains_.end(); ++it) {
      if ((*it)->touching(*this)) {
        if (m_actions.cut && (*it)->is_cuttable()) {
          terrains_.erase(it);
        }
        else if (m_actions.burn && (*it)->is_burnable()) {
          terrains_.erase(it);
        }
        else if (m_actions.push && (*it)->is_pushable()) {
          const Vector2f dist_vec = get_position() - (*it)->get_position()
          + 0.5f * (get_size() - (*it)->get_size());
          
          Vector2f old = (*it)->get_position();
          Vector2f pos = (*it)->get_position();
          if (abs(dist_vec.x) > abs(dist_vec.y)) {
            if (dist_vec.x > 0.0f && get_direction() == LEFT) {
              pos.x -= 32.0f;
            }
            else if (dist_vec.x < 0.0f && get_direction() == RIGHT) {
              pos.x += 32.0f;
            }
          }
          else {
            if (dist_vec.y > 0.0f && get_direction() == UP) {
              pos.y -= 32.0f;
            }
            else if (dist_vec.y < 0.0f && get_direction() == DOWN) {
              pos.y += 32.0f;
            }
          }
          
          (*it)->set_position(pos);
          bool killem = true;
          bool crushed = false;
          list<list<Terrain*>::iterator> kill;
          for (auto jt = terrains_.begin(); jt != terrains_.end(); ++jt) {
            if (*it == *jt) continue;
            if ((*it)->touching(**jt)) {
              if ((*jt)->is_crushable()) {
                kill.push_back(jt);
                crushed = true;
              }
              else {
                (*it)->set_position(old);
                killem = false;
                break;
              }
            }
          }
          if (killem) {
            for (int i = kill.size(); i > 0; --i) {
              terrains_.erase(kill.front());
              kill.pop_front();
            }
            if (crushed) terrains_.erase(it);
          }
          return;
        }
      }
    }
  }
}

bool Explorer::wielding_item() const {
  return m_item != nullptr;
}

const bool & Explorer::is_sliding() const {
  return m_sliding;
}

void Explorer::set_sliding(const bool &sliding_) {
  m_sliding = sliding_;
}

void Explorer::collide(const list<Terrain*> &terrains_) {
  m_sliding = false;
  for(auto it = terrains_.begin(); it != terrains_.end(); ++it) {
    if((*it)->touching(*this)) {
      (*it)->interact(*this);
      break;
    }
  }
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
