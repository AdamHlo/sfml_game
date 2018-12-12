#ifndef HANDLER_H
#define HANDLER_H
#include "gameObject.hpp"
#include <SFML/Graphics.hpp>
#include <memory>


class Handler{

public:

  bool collistionCourse(std::unique_ptr<GameObject> obj1, std::unique_ptr<GameObject> obj2, sf::Vector2f vec);

  bool collistionWithEnemy(std::unique_ptr<GameObject> player, std::vector<std::unique_ptr<GameObject>> enemies, sf::Vector2f direction);

  void handleMovement(std::unique_ptr<GameObject> player, std::vector<std::unique_ptr<GameObject>> enemies);

private:

  int movementSpeed = 5;

};

#endif
