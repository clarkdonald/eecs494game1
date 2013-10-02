//
//  Play_State.h
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "Explorer.h"
#include "Exit.h"
#include <Zeni/Widget.h>
#include <Zeni/Color.h>
#include <Zeni/Gamestate.hxx>
#include <Zeni/Timer.h>
#include <Zeni/Chronometer.h>
#include <vector>

class Item;
class Terrain;

struct Controls {
  Controls();
  
  bool up;
  bool left;
  bool down;
  bool right;
  bool speed_boost;
  bool pickup;
  bool drop;
  bool use;
};

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
  
    std::vector< std::vector<Game_Object*> > m_grid;
    Explorer m_explorer;
    Exit m_exit;
    bool win;
    std::list<Item*> m_items;
    std::list<Terrain*> m_terrains;
    Controls m_control;
    Zeni::Chronometer<Zeni::Time> m_chrono;
    float m_time_passed;
    Zeni::Color m_prev_clear_color;
};

#endif /* PLAY_STATE_H */
