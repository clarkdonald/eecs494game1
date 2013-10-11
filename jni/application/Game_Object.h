//
//  Game_Object.h
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <Zeni.h>
#include "Utility.h"

class Game_Object {
  public:
    Game_Object(const Position &position_);
    
    virtual ~Game_Object() {}
    
    virtual void render() const = 0;
  
    bool pseudo_touching(const Game_Object &rhs) const;
  
    bool touching(const Game_Object &rhs) const;
  
    const Position & get_position() const;
    
    const Zeni::Vector2f & get_size() const;
    
    const float get_radius() const;
  
    void set_position(const Position& position_);
    
  protected:
    void render(const Zeni::String &texture, const Zeni::Color &filter = Zeni::Color()) const;
  
  private:
    Position m_position;
    Zeni::Vector2f m_size;
};

#endif /* GAME_OBJECT_H */
