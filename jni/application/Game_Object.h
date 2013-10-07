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
    Game_Object(const int &floor_,
                const Zeni::Point2f &position_,
                const bool &blocking_,
                const float &speed_ = 0.0f);
    
    virtual ~Game_Object() {}
    
    virtual void render() const = 0;
    
    bool touching(const Game_Object &rhs) const;
  
    const int & get_floor() const;
  
    const Zeni::Point2f & get_position() const;
    
    const Zeni::Vector2f & get_size() const;
    
    const float get_radius() const;
  
    const bool & is_blocking() const;
  
    void set_floor(const int &floor_);
  
    void set_position(const Zeni::Point2f& position_);
    
  protected:
    void render(const Zeni::String &texture, const Zeni::Color &filter = Zeni::Color()) const;
  
  private:
    int m_floor;
    Zeni::Point2f m_position;
    Zeni::Vector2f m_size;
    bool m_blocking;
    float m_speed;
};

#endif /* GAME_OBJECT_H */
