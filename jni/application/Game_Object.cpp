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

Game_Object::Game_Object(const Position &position_)
: m_position(position_),
  m_size(OBJECT_SIZE)
{}

bool Game_Object::pseudo_touching(const Game_Object &rhs) const {
  if (m_position.floor != rhs.get_position().floor) return false;

  const Vector2f dist_vec = m_position.position - rhs.m_position.position + 0.5f * (m_size - rhs.m_size);
  const float dist2 = dist_vec * dist_vec * 1.3f;
  const float radius_sum = get_radius() + rhs.get_radius();
  return dist2 < radius_sum * radius_sum;
}

bool Game_Object::touching(const Game_Object &rhs) const {
  if (m_position.floor != rhs.get_position().floor) return false;
  
  float distance = UNIT_LENGTH - 3.0f;
  float centerX = get_position().position.x + (get_size().x / 2.0f);
  float centerY = get_position().position.y + (get_size().y / 2.0f);
  float rhsCenterX = rhs.get_position().position.x + (rhs.get_size().x / 2.0f);
  float rhsCenterY = rhs.get_position().position.y + (rhs.get_size().y / 2.0f);
  
  if ((abs(centerX - rhsCenterX) < distance) && (abs(centerY - rhsCenterY) < distance))
    return true;
  return false;
}

const Position & Game_Object::get_position() const {
  return m_position;
}

const Vector2f & Game_Object::get_size() const {
  return m_size;
}

const float Game_Object::get_radius() const {
  return 0.5f * m_size.magnitude();
}

void Game_Object::set_position(const Position& position_) {
  m_position = position_;
}

void Game_Object::render(const String &texture, const Color &filter) const {
  render_image(texture, // which texture to use
               m_position.position, // upper-left corner
               m_position.position + m_size, // lower-right corner
               0.0f, // rotation in radians
               1.0f, // scaling factor
               m_position.position + 0.5f * m_size, // point to rotate & scale about
               false, // whether or not to horizontally flip the texture
               filter); // what Color to "paint" the texture
}
