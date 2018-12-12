#ifndef GAMETABLE_H
#define GAMETABLE_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "gameObject.h"
#include <vector>
#include <string>

class GameTable{
public:
  GameTable(){
    this->player = GameObject("data/1B.png");
    this->enemies.push_back(GameObject("data/7.png"));
    this->enemies.push_back(GameObject("data/sprite.png"));
  }

  GameObject player;
  std::vector<GameObject> enemies;
};

#endif
