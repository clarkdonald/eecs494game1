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
                         const bool &blocking_,
                         const float &speed_)
: m_floor(floor_),
  m_position(position_),
  m_size(OBJECT_SIZE),
  m_blocking(blocking_),
  m_speed(speed_)
{}

bool Game_Object::touching(const Game_Object &rhs) const {
  if (m_floor != rhs.get_floor()) return false;
  
  float centerX = get_position().x + get_size().x/2.0f;
  float centerY = get_position().y + get_size().y/2.0f;
  float rhsCenterX = rhs.get_position().x + rhs.get_size().x/2.0f;
  float rhsCenterY = rhs.get_position().y + rhs.get_size().y/2.0f;
  
  if ((abs(centerX - rhsCenterX) < UNIT_LENGTH) &&
      (abs(centerY - rhsCenterY) < UNIT_LENGTH))
    return true;
  
  return false;
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
