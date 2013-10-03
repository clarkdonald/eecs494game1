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
#include <Zeni/Joysticks.h>
#include <Zeni/Game.h>

using namespace Zeni;
using std::make_pair;
using std::list;
using std::vector;
using std::bad_exception;
using std::endl;
using std::cerr;

using std::cout;

Play_State::Play_State()
: win(false),
  m_time_passed(0.0f),
  m_prev_clear_color(get_Video().get_clear_Color())
{
  Gamestate_Base::set_pausable(true);
  
  if (Map_Manager::get_Instance().empty()) {
    std::cerr << "No maps to play!" << endl;
    exit(1);
  }
  map_ptr = Map_Manager::get_Instance().get_next();
  //map_ptr = new Map();
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
    win = false;
    if (Map_Manager::get_Instance().empty()) get_Game().pop_state();
    delete map_ptr;
    map_ptr = Map_Manager::get_Instance().get_next();
  }
  //get_Video().set_2d();
  map_ptr->render();
}

void Play_State::perform_logic() {
  const float time_passed = m_chrono.seconds();
  const float time_step = time_passed - m_time_passed;
  m_time_passed = time_passed;
  win = map_ptr->perform_logic(m_control, time_step);
}
