//
//  Utility.h
//  game
//
//  Created by Donald Clark on 9/26/13.
//
//

#ifndef UTILITY_H
#define UTILITY_H

enum Direction {
  UP,
  DOWN,
  LEFT,
  RIGHT
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
};

struct Dimension {
  Dimension();
  Dimension(int width_, int height_, int floor_);
  int width;
  int height;
  int floor;
};

#endif /* UTILITY_H */
