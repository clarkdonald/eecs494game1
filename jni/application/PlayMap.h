//
//  PlayMap.h
//  game
//
//  Created by Donald Clark on 10/10/13.
//
//

#ifndef PLAY_MAP_H
#define PLAY_MAP_H

#include "Map.h"
#include <string>
#include <Zeni/Timer.h>
#include <Zeni/Chronometer.h>

class PlayMap : public Map {
public:
  PlayMap(const std::string &file);
  ~PlayMap();
  
  // show game objects on screen
  virtual void render() override;
  
  // perform logical operations of game object based on user input
  virtual Status perform_logic(Controls &controls_, const float &time_step_) override;
  
private:
  Zeni::Chronometer<Zeni::Time> floor_change;
  Zeni::Text_Box *floor_text;
};

#endif /* PLAY_MAP_H */
