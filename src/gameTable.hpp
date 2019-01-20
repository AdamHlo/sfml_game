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

  std::unique_ptr<GameObject> player;

  std::vector<std::unique_ptr<GameObject>> enemies;
};

#endif
