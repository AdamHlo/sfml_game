#ifndef HANDLER_H
#define HANDLER_H
#include "gameObject.hpp"
#include <SFML/Graphics.hpp>
#include <memory>


class Handler {
public:

  bool collistionCourse(GameObject* obj1, GameObject* obj2, sf::Vector2f vec);

  bool collistionWithEnemy(GameObject* player, std::vector<std::unique_ptr<GameObject>> &enemies, sf::Vector2f direction);

  void handleMovement(GameObject* player, std::vector<std::unique_ptr<GameObject>> &enemies);

  Handler(int height, int width);

private:

  int movementSpeed = 5;
  int height;
  int width;

};

#endif
