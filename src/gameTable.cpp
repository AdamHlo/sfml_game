#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.cpp"

class GameTable{
public:
  GameTable(){
    player = GameObject()

  }

  GameObject player, enemy1, enemy2;
}
