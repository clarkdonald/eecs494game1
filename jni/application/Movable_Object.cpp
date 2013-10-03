//
//  Movable_Object.cpp
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#include "Movable_Object.h"

using namespace Zeni;

Movable_Object::Movable_Object(const int &floor_,
                               const Point2f &position_,
                               const Vector2f &size_,
                               const Direction &direction_,
                               const bool &blocking_,
                               const float &speed_)
: Game_Object(floor_, position_, size_, blocking_, speed_),
  m_direction(direction_)
{}

const Direction & Movable_Object::get_direction() const {
  return m_direction;
}

void Movable_Object::face(const float &horizontal_, const float &vertical_) {
  if (horizontal_ != 0.0f) {
    m_direction = horizontal_ > 0.0f ? RIGHT : LEFT;
  }
  
  if (vertical_ != 0.0f) {
    m_direction = vertical_ > 0.0f ? DOWN : UP;
  }
}

void Movable_Object::move(const float &horizontal_, const float &vertical_)
{
  Point2f new_position(get_position());
  new_position.x += horizontal_;
  new_position.y += vertical_;
  set_position(new_position);
}
