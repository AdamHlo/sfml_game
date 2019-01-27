#include "gameObject.hpp"
#include "gameTable.hpp"
#include <memory>

GameTable::GameTable() {
  this->player = std::unique_ptr<Player>(new Player("data/player.png"));
  this->gameObjects.push_back(
      std::unique_ptr<GameObject>(new GameObject("data/platform.png")));
  this->gameObjects.push_back(
      std::unique_ptr<GameObject>(new GameObject("data/platform.png")));
  this->gameObjects.push_back(
      std::unique_ptr<GameObject>(new GameObject("data/platform.png")));
  this->gameObjects.push_back(
      std::unique_ptr<GameObject>(new GameObject("data/platform.png")));
  this->gameObjects.push_back(
      std::unique_ptr<GameObject>(new GameObject("data/platform.png")));
  this->gameObjects.push_back(
      std::unique_ptr<GameObject>(new GameObject("data/platform.png")));
  this->gameObjects.push_back(
      std::unique_ptr<GameObject>(new GameObject("data/platform.png")));
  this->gameObjects.push_back(
      std::unique_ptr<GameObject>(new GameObject("data/platform.png")));
  this->gameObjects.push_back(
      std::unique_ptr<GameObject>(new GameObject("data/platform.png")));
  this->gameObjects.push_back(
      std::unique_ptr<GameObject>(new GameObject("data/platform.png")));
}
