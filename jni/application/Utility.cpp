//
//  Utility.cpp
//  game
//
//  Created by Donald Clark on 10/2/13.
//
//

#include "Utility.h"
#include <Zeni/Widget.h>
#include <Zeni/Colors.h>
#include <Zeni/Color.h>

using namespace Zeni;

Position::Position(int floor_, Zeni::Point2f position_)
: floor(floor_),
  position(position_)
{}

Controls::Controls()
: up(false),
  left(false),
  down(false),
  right(false),
  speed_boost(false),
  pickup(false),
  drop(false),
  use(false),
  cheat0(false),
  cheat1(false),
  cheat2(false)
{}

Dimension::Dimension()
: width(0),
  height(0),
  floor(0)
{}

Dimension::Dimension(int width_, int height_, int floor_)
: width(width_),
  height(height_),
  floor(floor_)
{}

void transition() {
  Chronometer<Time> timer;
  timer.start();
  while (timer.seconds() < 1.0f) {
    Text_Box m_text_box(Point2f(), Point2f(800.0f, 600.0f), "system_36_800x600", "", Color());
    m_text_box.give_BG_Renderer(new Widget_Renderer_Color(get_Colors()["black"]));
    m_text_box.render();
  }
}
