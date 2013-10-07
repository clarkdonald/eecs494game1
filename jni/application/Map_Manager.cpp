//
//  Map_Manager.cpp
//  game
//
//  Created by Donald Clark on 10/2/13.
//
//

#include "Map_Manager.h"
#include "Map.h"
#include "Utility.h"
#include <iostream>
#include <fstream>

using namespace Zeni;
using std::string;
using std::cerr;
using std::endl;
using std::bad_exception;

Map_Manager& Map_Manager::get_Instance()
{
  static Map_Manager Map_Manager;
  return Map_Manager;
}

Map_Manager::Map_Manager()
: index(0)
{
  for (int i = 0; i < NUM_FILES; ++i) {
    string str = "../../../jni/application/level" + std::to_string(i) + ".txt";
    files.push_back(str);
  }
}

const int & Map_Manager::get_files_left() const {
  return index;
}

bool Map_Manager::empty() const {
  return (files.size() - index) <= 0;
}

void Map_Manager::reset() {
  index = 0;
}

Map* Map_Manager::get_next() {
  if (empty()) throw new bad_exception();
  Map* map_ptr;
  try {
    map_ptr = new Map(files[index++].c_str());
  }
  catch (bad_exception e) {
    cerr << "Map construction failed from get_next!" << endl;
    throw e;
  }
  return map_ptr;
}

Map* Map_Manager::get(const string &file) {
  Map* map_ptr;
  try {
    map_ptr = new Map(file);
  }
  catch (bad_exception e) {
    cerr << "Map construction failed from get!" << endl;
    throw e;
  }
  return map_ptr;
}
