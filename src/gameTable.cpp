#include "gameTable.hpp"
#include "gameObject.hpp"
#include <memory>


GameTable::GameTable(){

  this->player = std::shared_ptr<GameObject>(std::move(new GameObject("data/1B.png")));
  this->enemies.push_back(std::shared_ptr<GameObject>(std::move(new GameObject("data/7.png"))));
  this->enemies.push_back(std::shared_ptr<GameObject>(std::move(new GameObject("data/sprite.png"))));

}
