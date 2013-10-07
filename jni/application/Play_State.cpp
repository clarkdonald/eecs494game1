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
using std::exit;

Play_State::Play_State()
: m_time_passed(0.0f),
  m_prev_clear_color(get_Video().get_clear_Color())
{
  Gamestate_Base::set_pausable(true);
  if (Map_Manager::get_Instance().empty()) {
    cerr << "No maps to play!" << endl;
    get_Game().pop_state();
  }
  map_ptr = Map_Manager::get_Instance().get_next();
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
      
    default:
      Gamestate_Base::on_key(event); // Let Gamestate_Base handle it
      break;
  }
}

void Play_State::render() {
  map_ptr->render();
}

void Play_State::perform_logic() {
  const float time_passed = m_chrono.seconds();
  const float time_step = time_passed - m_time_passed;
  m_time_passed = time_passed;
  if (map_ptr->perform_logic(m_control, time_step)) {
    delete map_ptr;
    if (Map_Manager::get_Instance().empty()) get_Game().pop_state();
    else map_ptr = Map_Manager::get_Instance().get_next();
  }
}
