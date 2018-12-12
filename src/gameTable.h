#ifndef GAMETABLE_H
#define GAMETABLE_H
#include <SFML/Graphics.hpp>
#include "gameObject.h"
#include <vector>
#include <string>

class GameTable{
public:
  GameTable();
  GameObject player;
  std::vector<GameObject> enemies;
};

#endif