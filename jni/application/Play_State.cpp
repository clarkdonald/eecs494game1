//
//  Play_State.cpp
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#include "Play_State.h"
#include "Terrain.h"
#include "Item.h"
#include "Terrain_Factory.h"
#include "Item_Factory.h"
#include <utility>
#include <list>
#include <Zeni/Image.h>
#include <Zeni/XML.h>
#include <Zeni/Video.h>
#include <Zeni/Window.h>

using namespace Zeni;
using std::make_pair;
using std::list;
using std::vector;

Controls::Controls()
: up(false),
  left(false),
  down(false),
  right(false),
  speed_boost(false),
  pickup(false),
  drop(false),
  use(false)
{}

Play_State::Play_State()
: m_grid(20, vector<Game_Object*>(15, nullptr)),
  m_explorer(Point2f(0.0f, 0.0f), Vector2f(32.0f, 32.0f)),
  m_exit(Point2f(608.0f, 450.0f), Vector2f(32.0f, 32.0f)),
  win(false),
  m_time_passed(0.0f),
  m_prev_clear_color(get_Video().get_clear_Color())
{
  Gamestate_Base::set_pausable(true);
  
  float pos = 0.0f;
  for (int i = 0; i < 20; ++i, pos += 32.0f) {
    if (i == 10) continue;
    m_terrains.push_back(create_terrain("Water", Point2f(pos, 320.0f), Vector2f(32.0f, 32.0f)));
    m_terrains.push_back(create_terrain("Water", Point2f(pos, 352.0f), Vector2f(32.0f, 32.0f)));
  }
  
  pos = 352.0f;
  for (int i = 0; i < 10; ++i, pos += 32.0f) {
    m_terrains.push_back(create_terrain("Ice", Point2f(pos, 96.0f), Vector2f(32.0f, 32.0f)));
  }
  
  pos = 0.0f;
  for (int i = 0; i < 15; ++i, pos += 32.0f) {
    m_terrains.push_back(create_terrain("Water", Point2f(320.0f, pos), Vector2f(32.0f, 32.0f)));
  }
  
  m_terrains.push_back(create_terrain("Ladder_Down", Point2f(200.0f, 420.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Ladder_Up", Point2f(100.0f, 100.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Boulder", Point2f(50.0f, 150.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Hole", Point2f(200.0f, 280.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Tree", Point2f(100.0f, 280.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Tree", Point2f(400.0f, 280.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Tree", Point2f(370.0f, 240.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Tree", Point2f(440.0f, 220.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Tree", Point2f(400.0f, 200.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Tree", Point2f(600.0f, 110.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Tree", Point2f(410.0f, 120.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Tree", Point2f(520.0f, 230.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Tree", Point2f(400.0f, 420.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Tree", Point2f(450.0f, 420.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Tree", Point2f(520.0f, 400.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Fire", Point2f(140.0f, 420.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Fire", Point2f(30.0f, 390.0f), Vector2f(32.0f, 32.0f)));
  m_terrains.push_back(create_terrain("Teleport", Point2f(550.0f, 256.0f), Vector2f(32.0f, 32.0f), Point2f(500.0f, 400.0f)));
  m_terrains.push_back(create_terrain("Teleport", Point2f(520.0f, 450.0f), Vector2f(32.0f, 32.0f), Point2f(60.0f, 320.0f)));
  
  m_items.push_back(create_item("Pill", Point2f(280.0f, 50.0f), Vector2f(32.0f, 32.0f)));
  m_items.push_back(create_item("Axe", Point2f(500.0f, 60.0f), Vector2f(32.0f, 32.0f)));
}

void Play_State::on_push() {
  m_chrono.start();
  get_Window().mouse_hide(true);
  get_Video().set_clear_Color(Color(1.0f, 0.26f, 0.13f, 0.0f));
}

void Play_State::on_pop() {
  m_chrono.stop();
  get_Window().mouse_hide(false);
  get_Video().set_clear_Color(m_prev_clear_color);
}

void Play_State::on_key(const SDL_KeyboardEvent &event) {
  switch(event.keysym.sym) {
    case SDLK_UP:
      m_control.up = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_LEFT:
      m_control.left = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_DOWN:
      m_control.down = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_RIGHT:
      m_control.right = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_a:
      m_control.pickup = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_s:
      m_control.drop = event.type == SDL_KEYDOWN;
      
    case SDLK_d:
      m_control.use = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_SPACE:
      m_control.speed_boost = event.type == SDL_KEYDOWN;
      break;
      
    default:
      Gamestate_Base::on_key(event); // Let Gamestate_Base handle it
      break;
  }
}

void Play_State::render() {
  //get_Window().get_width();
  //get_Video().set_2d(make_pair(m_explorer.get_position() + Vector2f(0.0f,0.0f),
  //                             m_explorer.get_position() + Vector2f(854.0f,480.0f)), true);
  //get_Video().set_2d(make_pair(Point2f(0.0f, 0.0f), Point2f(854.0f, 480.0f)), true);
  if (win) {
    Text_Box m_text_box(Point2f(), Point2f(800.0f, 600.0f), "system_36_800x600", "YOU WIN!!!", Color());
    m_text_box.give_BG_Renderer(new Widget_Renderer_Color(get_Colors()["black"]));
    m_text_box.render();
  }
  else {
    get_Video().set_2d();
    //render_image("ground", Point2f(0.0f, 0.0f), Point2f(600.0f, 800.0f));
    for(auto it = m_terrains.begin(); it != m_terrains.end(); ++it) {
      (*it)->render();
    }
    for(auto it = m_items.begin(); it != m_items.end(); ++it) {
      (*it)->render();
    }
    m_exit.render();
    m_explorer.render();
  }
}

void Play_State::perform_logic() {
  const float time_passed = m_chrono.seconds();
  const float time_step = time_passed - m_time_passed;
  m_time_passed = time_passed;

  m_explorer.face(m_control.right - m_control.left, m_control.down - m_control.up);
  
  for (auto it = m_terrains.begin(); it != m_terrains.end(); ++it) {
    if ((*it)->is_blocking() && m_explorer.touching(**it)) {
      const Vector2f dist_vec = m_explorer.get_position() - (*it)->get_position()
        + 0.5f * (m_explorer.get_size() - (*it)->get_size());
      if (abs(dist_vec.x) > abs(dist_vec.y)) {
        if (dist_vec.x > 0.0f) {
          m_control.left = false;
        }
        else {
          m_control.right = false;
        }
      }
      else {
        if (dist_vec.y > 0.0f) {
          m_control.up = false;
        }
        else {
          m_control.down = false;
        }
      }
    }
  }
  
  if(m_explorer.get_position().x < 0.0f) {
    m_control.left = false;
  }
  
  if (m_explorer.get_position().x > 0.0f + get_Window().get_width()) {
    m_control.right = false;
  }
  
  if (m_explorer.get_position().y < 0.0f) {
    m_control.up = false;
  }
  
  if(m_explorer.get_position().y > 0.0f + get_Window().get_height()) {
    m_control.down = false;
  }

  if (!m_explorer.is_sliding()) {
    float multiplier = time_step * (m_control.speed_boost ? 150.0f : 100.0f);
    m_explorer.move((m_control.right - m_control.left) * multiplier,
                    (m_control.down - m_control.up) * multiplier);
  }

  if (m_exit.touching(m_explorer)) {
    win = true;
  }
  
  m_explorer.collide(m_terrains);
  m_explorer.pickup_item(m_control.pickup, m_items);
  m_explorer.drop_item(m_control.drop, m_items);
  m_explorer.use_item(m_control.use, m_terrains);
}
