//
//  Play_State.cpp
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#include "Play_State.h"
#include "Map_Manager.h"
#include "Map.h"
#include <utility>
#include <list>
#include <iostream>
#include <Zeni/Image.h>
#include <Zeni/XML.h>
#include <Zeni/Video.hxx>
#include <Zeni/Video.h>
#include <Zeni/Window.h>
#include <Zeni/Colors.h>
#include <Zeni/Joysticks.h>
#include <Zeni/Game.h>

using namespace Zeni;
using std::make_pair;
using std::list;
using std::vector;
using std::bad_exception;
using std::endl;
using std::cerr;
using std::exit;

Play_State::Play_State()
: m_time_passed(0.0f)
{
  Gamestate_Base::set_pausable(true);
  if (Map_Manager::get_Instance().empty()) {
    cerr << "No maps to play!" << endl;
    get_Game().pop_state();
  }
  map_ptr = Map_Manager::get_Instance().get_next();
  level_info = new Text_Box(Point2f(), Point2f(800.0f, 600.0f), "title", "", Color());
  level_info->give_BG_Renderer(new Widget_Renderer_Color(get_Colors()["black"]));
}

void Play_State::on_push() {
  m_chrono.start();
  get_Window().mouse_hide(true);
}

void Play_State::on_pop() {
  m_chrono.stop();
  get_Window().mouse_hide(false);
  Map_Manager::get_Instance().reset();
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
      
    case SDLK_s:
      m_control.pickup = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_d:
      m_control.drop = event.type == SDL_KEYDOWN;
      
    case SDLK_f:
      m_control.use = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_SPACE:
      m_control.speed_boost = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_EQUALS:
      m_control.cheat0 = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_MINUS:
      m_control.cheat1 = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_0:
      m_control.cheat2 = event.type == SDL_KEYDOWN;
      break;
      
    case SDLK_p:
      m_control.retry = event.type == SDL_KEYDOWN;
      break;
      
    default:
      Gamestate_Base::on_key(event); // Let Gamestate_Base handle it
      break;
  }
}

void Play_State::render() {
  map_ptr->render();
  if (level_info_timer.is_running()) {
    if (level_info_timer.seconds() < 2.0f) {
      level_info->render();
    }
    else {
      level_info_timer.stop();
    }
  }
}

void Play_State::change_map() {
  if (!map_ptr->get_level_info().empty()) {
    level_info->set_upper_left(map_ptr->get_explorer_position() - Vector2f(300.0f, 200.0f));
    level_info->set_lower_right(map_ptr->get_explorer_position() + Vector2f(500.0f, 400.0f));
    level_info->set_text(String(map_ptr->get_level_info()));
    level_info_timer.reset();
    level_info_timer.start();
  }
  cheat_timer.reset();
  cheat_timer.start();
}

void Play_State::perform_logic() {
  const float time_passed = m_chrono.seconds();
  const float time_step = time_passed - m_time_passed;
  m_time_passed = time_passed;
  
  if (m_control.retry) {
    delete map_ptr;
    map_ptr = Map_Manager::get_Instance().get_previous();
    change_map();
  }
  
  if (!cheat_timer.is_running()) {
    if (m_control.cheat0 && m_control.cheat1 && m_control.cheat2) {
      if (Map_Manager::get_Instance().empty()) {
        get_Game().pop_state();
      }
      else {
        map_ptr = Map_Manager::get_Instance().get_next();
        change_map();
      }
    }
  }
  else {
    if (cheat_timer.seconds() > 1.0f) {
      cheat_timer.stop();
    }
  }
  
  if (!level_info_timer.is_running() || !cheat_timer.is_running()) {
    switch (map_ptr->perform_logic(m_control, time_step)) {
      case UNDONE:
        break;
        
      case DONE:
        delete map_ptr;
        if (Map_Manager::get_Instance().empty()) {
          get_Game().pop_state();
        }
        else {
          map_ptr = Map_Manager::get_Instance().get_next();
          change_map();
        }
        break;
        
      case SKIP:
        delete map_ptr;
        if (Map_Manager::get_Instance().empty()) {
          get_Game().pop_state();
        }
        else {
          map_ptr = Map_Manager::get_Instance().skip();
          change_map();
        }
        break;
        
      default:
        throw new bad_exception;
    }
  }
}
