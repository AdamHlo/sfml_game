#ifndef HANDLER_H
#define HANDLER_H
#include "gameObject.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

class Handler {
public:
  bool collisionCourse(GameObject *obj1, GameObject *obj2, sf::Vector2f vec);

  bool collision(Player *player,
                 std::vector<std::unique_ptr<GameObject>> &gameObjects,
                 sf::Vector2f direction);

  void handleMovement(Player *player,
                      std::vector<std::unique_ptr<GameObject>> &gameObjects,
                      sf::Vector2f direction, float delta_t);

  bool collisionWithBoundary(Player *player, sf::Vector2f direction);

  sf::Vector2f getMovementInput();

  void handleJump(Player *player);

  Handler(int height, int width, double gravity, double jumpVelocity);

private:
  int movementSpeed = 5;
  int height;
  int width;
  double gravity;
  double jumpVelocity;
};

#endif
