//
//  Utility.h
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#ifndef UTILITY_H
#define UTILITY_H

#include <Zeni/Coordinate.h>

const float UNIT_LENGTH = 32.0f;
const Zeni::Vector2f OBJECT_SIZE = Zeni::Vector2f(UNIT_LENGTH, UNIT_LENGTH);

enum Direction {
  UP,
  DOWN,
  LEFT,
  RIGHT
};

struct Position {
  Position(int floor_, Zeni::Point2f position_);
  int floor;
  Zeni::Point2f position;
};

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
  bool cheat0;
  bool cheat1;
  bool cheat2;
  bool retry;
};

struct Dimension {
  Dimension();
  Dimension(int width_, int height_, int floor_);
  int width;
  int height;
  int floor;
};

void transition();

#endif /* UTILITY_H */
