#include "handler.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

Handler::Handler(int height, int width, double gravity, double jumpVelocity) {
  this->height = height;
  this->width = width;
  this->gravity = gravity;
  this->jumpVelocity = jumpVelocity;
}

bool Handler::collisionCourse(GameObject *obj1, GameObject *obj2,
                              sf::Vector2f vec) {
  int leftFirst = obj1->getLeftTop().x;
  int topFirst = obj1->getLeftTop().y;
  int rightFirst = obj1->getRightBottom().x;
  int bottomFirst = obj1->getRightBottom().y;
  int left = obj2->getLeftTop().x;
  int top = obj2->getLeftTop().y;
  int right = obj2->getRightBottom().x;
  int bottom = obj2->getRightBottom().y;

  return ((topFirst + vec.y < bottom and bottomFirst + vec.y > top) and
          (rightFirst + vec.x > left and leftFirst + vec.x < right));
}

bool Handler::collision(GameObject *player,
                        std::vector<std::unique_ptr<GameObject>> &gameObjects,
                        sf::Vector2f direction) {
  for (std::unique_ptr<GameObject> &game_object : gameObjects) {
    if (collisionCourse(player, game_object.get(), direction)) {
      return true;
    }
  }
  return false;
}

bool Handler::collisionWithBoundary(GameObject *player,
                                    sf::Vector2f direction) {
  int left = player->getLeftTop().x;
  int top = player->getLeftTop().y;
  int right = player->getRightBottom().x;
  int bottom = player->getRightBottom().y;
  return !(left + direction.x > 0 and top + direction.y > 0 and
           right + direction.x < this->width and
           bottom + direction.y < this->height);
}

void Handler::handleMovement(
    GameObject *player, std::vector<std::unique_ptr<GameObject>> &gameObjects,
    sf::Vector2f direction, float delta_t) {
  if (!collision(player, gameObjects, direction) and
      !collisionWithBoundary(player, direction)) {
    player->move(direction);
  }

  sf::Vector2f fall_vector =
      sf::Vector2f(0, delta_t * (-player->vertical_velocity));

  if (!collision(player, gameObjects, fall_vector) and
      !collisionWithBoundary(player, fall_vector)) {
    player->move(fall_vector);
    player->changeVelocity(delta_t * this->gravity);
  } else {
    player->setVelocity(0);
  }
}

void Handler::handleJump(GameObject *player) {
  if (player->vertical_velocity == 0 and
      sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    player->setVelocity(this->jumpVelocity);
  }
}

sf::Vector2f Handler::getMovementInput() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    return sf::Vector2f(-this->movementSpeed, 0);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    return sf::Vector2f(this->movementSpeed, 0);
  } else {
    return sf::Vector2f(0, 0);
  }
}
