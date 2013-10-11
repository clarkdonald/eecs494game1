//
//  Bucket.cpp
//  game
//
//  Created by Donald Clark on 10/2/13.
//
//

#include "Bucket.h"

using namespace Zeni;

Bucket::Bucket(const Position &position_)
: Item(position_)
{}

void Bucket::render() const {
  Game_Object::render("twig");
}

bool Bucket::for_extinguishing() const {
  return true;
}

bool Bucket::for_water_filling() const {
  return true;
}

