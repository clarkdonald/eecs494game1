//
//  Movable_Object.cpp
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#include "Movable_Object.h"
#include "Terrain.h"
#include "Boulder.h"

using namespace Zeni;
using std::list;
using std::bad_exception;

Sliding::Sliding()
: is_sliding(false)
{}

Movable_Object::Movable_Object(const Position &position_,
                               const Direction &direction_)
: Game_Object(position_),
  direction(direction_)
{}

const Direction & Movable_Object::get_direction() const {
  return direction;
}

const bool & Movable_Object::is_sliding() const {
  return sliding.is_sliding;
}

const Direction & Movable_Object::get_sliding_direction() const {
  if (!is_sliding()) throw new bad_exception;
  return sliding.direction;
}

void Movable_Object::reset_sliding() {
  sliding.is_sliding = false;
}

void Movable_Object::set_sliding(const Direction &direction_) {
  sliding.is_sliding = true;
  sliding.direction = direction_;
}

void Movable_Object::face(const float &horizontal_, const float &vertical_) {
  if (horizontal_ != 0.0f) {
    direction = horizontal_ > 0.0f ? RIGHT : LEFT;
  }
  
  if (vertical_ != 0.0f) {
    direction = vertical_ > 0.0f ? DOWN : UP;
  }
}

void Movable_Object::move(float horizontal_,
                          float vertical_,
                          const list<Boulder*> &boulders,
                          const list<Terrain*> &terrains,
                          const Dimension &dimension)
{
  Position old_position(get_position());
  
  // check current terrain for forced movement
  bool no_force_move = true;
  for (auto it = terrains.begin(); it != terrains.end(); ++it) {
    if (!no_force_move) return;

    if (touching(**it) && (*it)->is_forced_move()) {
      (*it)->interact(*this);

      // floor movement terrain collision detection
      float floor = get_position().floor - old_position.floor;
      if (get_position().floor != old_position.floor) {
        no_force_move = false;
        Position no_floor_position = get_position();
        no_floor_position.floor -= floor;
        for (auto it = terrains.begin(); it != terrains.end(); ++it) {
          if (touching(**it) && (*it)->is_movable_blocking()) {
            set_position(no_floor_position);
            no_force_move = true;
            break;
          }
        }
        for (auto it = boulders.begin(); it != boulders.end(); ++it) {
          if (touching(**it) && (*it)->is_movable_blocking()) {
            set_position(no_floor_position);
            no_force_move = true;
            break;
          }
        }
      }

      // horizontal terrain collision detection
      float horizontal = get_position().position.x - old_position.position.x;
      if (get_position().position.x != old_position.position.x) {
        no_force_move = false;
        Position no_horizontal_position = get_position();
        no_horizontal_position.position.x -= horizontal;
        if (get_position().position.x > 0.0f &&
            get_position().position.x < (dimension.width*UNIT_LENGTH - UNIT_LENGTH)) {
          for (auto it = terrains.begin(); it != terrains.end(); ++it) {
            if (touching(**it) && (*it)->is_movable_blocking()) {
              set_position(no_horizontal_position);
              no_force_move = true;
              break;
            }
          }
          for (auto it = boulders.begin(); it != boulders.end(); ++it) {
            if (touching(**it) && (*it)->is_movable_blocking()) {
              set_position(no_horizontal_position);
              no_force_move = true;
              break;
            }
          }
        }
        else {
          set_position(no_horizontal_position);
          no_force_move = true;
        }
      }

      // vertical terrain collision detection
      float vertical = get_position().position.y - old_position.position.y;
      if (get_position().position.y != old_position.position.y) {
        no_force_move = false;
        Position no_vertical_position = get_position();
        no_vertical_position.position.y -= vertical;
        if (get_position().position.y > 0.0f &&
            get_position().position.y < (dimension.height*UNIT_LENGTH - UNIT_LENGTH)) {
          for (auto it = terrains.begin(); it != terrains.end(); ++it) {
            if (touching(**it) && (*it)->is_movable_blocking()) {
              set_position(no_vertical_position);
              no_force_move = true;
              break;
            }
          }
          for (auto it = boulders.begin(); it != boulders.end(); ++it) {
            if (touching(**it) && (*it)->is_movable_blocking()) {
              set_position(no_vertical_position);
              no_force_move = true;
              break;
            }
          }
        }
        else {
          set_position(no_vertical_position);
          no_force_move = true;
        }
      }
    }
  }
  reset_sliding();

  // horizontal terrain collision detection
  if (horizontal_ != 0.0f) {
    Position new_h_position(get_position());
    new_h_position.position.x += horizontal_;
    set_position(new_h_position);
    if (get_position().position.x > 0.0f &&
        get_position().position.x < (dimension.width*UNIT_LENGTH - UNIT_LENGTH)) {
      for (auto it = terrains.begin(); it != terrains.end(); ++it) {
        if (touching(**it) && (*it)->is_movable_blocking()) {
          set_position(old_position);
          break;
        }
      }
      for (auto it = boulders.begin(); it != boulders.end(); ++it) {
        if (touching(**it) && (*it)->is_movable_blocking()) {
          set_position(old_position);
          break;
        }
      }
    }
    else {
      set_position(old_position);
    }
  }

  // vertical terrain collision detection
  if (vertical_ != 0.0f) {
    old_position = get_position();
    Position new_v_position(get_position());
    new_v_position.position.y += vertical_;
    set_position(new_v_position);
    if (get_position().position.y > 0.0f &&
        get_position().position.y < (dimension.height*UNIT_LENGTH - UNIT_LENGTH)) {
      for (auto it = terrains.begin(); it != terrains.end(); ++it) {
        if (touching(**it) && (*it)->is_movable_blocking()) {
          set_position(old_position);
          break;
        }
      }
      for (auto it = boulders.begin(); it != boulders.end(); ++it) {
        if (touching(**it) && (*it)->is_movable_blocking()) {
          set_position(old_position);
          break;
        }
      }
    }
    else {
      set_position(old_position);
    }
  }
}
