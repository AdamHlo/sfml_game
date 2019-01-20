#include "handler.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

Handler::Handler(int height, int width, double gravity) {
  this->height = height;
  this->width = width;
  this->gravity = gravity;
}

bool Handler::collistionCourse(GameObject *obj1, GameObject *obj2,
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

bool Handler::collistionWithEnemy(
    GameObject *player, std::vector<std::unique_ptr<GameObject>> &enemies,
    sf::Vector2f direction) {
  for (std::unique_ptr<GameObject> &enemy : enemies) {
    if (collistionCourse(player, enemy.get(), direction)) {
      return true;
    }
  }
  return false;
}

bool Handler::collisionWithBoundary(GameObject *player,
                                    sf::Vector2f direction) {
  if (player->getPosition().x + direction.x > 0 or
      player->getPosition().x + player->getTextureRect().width + direction.x <
          this->width or
      player->getPosition().y + direction.y > 0 or
      player->getPosition().y + player->getTextureRect().height + direction.y <
          this->height) {
    return false;
  } else {
    return true;
  }
}

void Handler::handleMovement(GameObject *player,
                             std::vector<std::unique_ptr<GameObject>> &enemies,
                             sf::Vector2f direction, float delta_t) {
  if (!collistionWithEnemy(player, enemies, direction) and
      !collisionWithBoundary(player, direction)) {
    player->move(direction);
  }

  sf::Vector2f fall_vector =
      sf::Vector2f(0, delta_t * (-player->vertical_velocity));

  if (!collistionWithEnemy(player, enemies, fall_vector) and
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
    player->setVelocity(1200);
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
