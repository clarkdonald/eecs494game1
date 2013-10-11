//
//  Play_State.h
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "Utility.h"
#include <Zeni/Widget.h>
#include <Zeni/Color.h>
#include <Zeni/Gamestate.hxx>
#include <Zeni/Timer.h>
#include <Zeni/Chronometer.h>
#include <vector>

class Map;

class Play_State : public Zeni::Gamestate_Base {
  Play_State(const Play_State &);
  
  Play_State operator=(const Play_State &);
    
  public:
    Play_State();
  
  private:
    void on_push();
    
    void on_pop();
    
    void on_key(const SDL_KeyboardEvent &event);
    
    void render();
    
    void perform_logic();
  
    void change_map();
  
    Map* map_ptr;
    Controls m_control;
    Zeni::Chronometer<Zeni::Time> m_chrono;
    float m_time_passed;
    Zeni::Text_Box *level_info;
    Zeni::Chronometer<Zeni::Time> cheat_timer;
    Zeni::Chronometer<Zeni::Time> level_info_timer;
};

#endif /* PLAY_STATE_H */
