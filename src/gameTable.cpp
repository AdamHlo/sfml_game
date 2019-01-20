#include "gameObject.hpp"
#include "gameTable.hpp"
#include <memory>

GameTable::GameTable() {
  this->player = std::unique_ptr<GameObject>(new GameObject("data/1B.png"));
  this->enemies.push_back(
      std::unique_ptr<GameObject>(new GameObject("data/7.png")));
  this->enemies.push_back(
      std::unique_ptr<GameObject>(new GameObject("data/sprite.png")));
}
