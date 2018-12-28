#ifndef GAMETABLE_H
#define GAMETABLE_H
#include <SFML/Graphics.hpp>
#include "gameObject.hpp"
#include <vector>
#include <string>
#include <memory>

class GameTable {
public:

  GameTable();

  std::unique_ptr<GameObject> player;

  std::vector<std::unique_ptr<GameObject>> enemies;

};

#endif
