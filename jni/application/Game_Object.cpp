//
//  Game_Object.cpp
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#include "Game_Object.h"
#include <Zeni/EZ2D.h>

using namespace Zeni;

Game_Object::Game_Object(const int &floor_,
                         const Point2f &position_,
                         const Vector2f &size_,
                         const bool &blocking_,
                         const float &speed_)
: m_floor(floor_),
  m_position(position_),
  m_size(size_),
  m_blocking(blocking_),
  m_speed(speed_)
{}

bool Game_Object::touching(const Game_Object &rhs) const {
  const Vector2f dist_vec = m_position - rhs.m_position + 0.5f * (m_size - rhs.m_size);
  const float dist2 = dist_vec * dist_vec;
  const float radius_sum = get_radius() + rhs.get_radius();
  return (dist2 < radius_sum * radius_sum) && (m_floor == rhs.get_floor());
}

const int & Game_Object::get_floor() const {
  return m_floor;
}

const Point2f & Game_Object::get_position() const {
  return m_position;
}

const Vector2f & Game_Object::get_size() const {
  return m_size;
}

const float Game_Object::get_radius() const {
  return 0.5f * m_size.magnitude();
}

const bool & Game_Object::is_blocking() const {
  return m_blocking;
}

void Game_Object::set_floor(const int &floor_) {
  m_floor = floor_;
}

void Game_Object::set_position(const Zeni::Point2f &position_) {
  m_position.x = position_.x;
  m_position.y = position_.y;
}

void Game_Object::render(const String &texture, const Color &filter) const {
  render_image(texture, // which texture to use
               m_position, // upper-left corner
               m_position + m_size, // lower-right corner
               0.0f, // rotation in radians
               1.0f, // scaling factor
               m_position + 0.5f * m_size, // point to rotate & scale about
               false, // whether or not to horizontally flip the texture
               filter); // what Color to "paint" the texture
}
