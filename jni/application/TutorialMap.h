//
//  TutorialMap.h
//  game
//
//  Created by Donald Clark on 10/10/13.
//
//

#ifndef TUTORIAL_MAP_H
#define TUTORIAL_MAP_H

#include "Map.h"
#include <Zeni/Widget.h>
#include <string>

class Skip;

class TutorialMap : public Map {
  public:
    TutorialMap(const std::string &file);
    ~TutorialMap();
  
    // show game objects on screen
    virtual void render() override;
    
    // perform logical operations of game object based on user input
    virtual Status perform_logic(Controls &controls_, const float &time_step_) override;
  
  private:
    Skip *skip;
    Zeni::Text_Box *tb;
};

#endif /* TUTORIAL_MAP_H */
