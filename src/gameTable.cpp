#include "gameTable.h"
#include "gameObject.h"
#include <string>

const std::string path1 = "data/1B.png";
const std::string path2 = "data/7.png";
const std::string path3 = "data/sprite.png";

GameTable::GameTable(){
  this->player = GameObject(path1);
  this->enemies.push_back(GameObject(path2));
  this->enemies.push_back(GameObject(path3));
}
