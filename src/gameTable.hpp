#ifndef GAMETABLE_H
#define GAMETABLE_H
#include "gameObject.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>

class GameTable {
public:
  GameTable();

  std::unique_ptr<Player> player;

  std::vector<std::unique_ptr<GameObject>> gameObjects;

  // std::vector<std::unique_ptr<GameObject>> enemies;
};

#endif
