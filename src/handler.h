#ifndef HANDLER_H
#define HANDLER_H
#include "gameObject.h"
#include <SFML/Graphics.hpp>


class Handler{

public:

  bool collistionCourse(GameObject obj1, GameObject obj2, sf::Vector2f vec);

  bool collistionWithEnemy(GameObject player, std::vector<GameObject> enemies, sf::Vector2f direction);

  void handleMovement(GameObject player, std::vector<GameObject> enemies);

private:

  int movementSpeed = 5;

};

#endif
