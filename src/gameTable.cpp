#include "gameTable.h"
#include "gameObject.h"


GameTable::GameTable(){
  this->player = GameObject("data/1B.png");
  this->enemies.push_back(GameObject("data/7.png"));
  this->enemies.push_back(GameObject("data/sprite.png"));
}
