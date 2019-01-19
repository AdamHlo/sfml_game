#include "handler.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>


Handler::Handler(int height, int width) {
  this->height = height;
  this->width = width;
}


bool Handler::collistionCourse(GameObject* obj1, GameObject* obj2, sf::Vector2f vec) {
  int leftFirst = obj1->getLeftTop().x;
  int topFirst = obj1->getLeftTop().y;
  int rightFirst = obj1->getRightBottom().x;
  int bottomFirst = obj1->getRightBottom().y;
  int left = obj2->getLeftTop().x;
  int top = obj2->getLeftTop().y;
  int right = obj2->getRightBottom().x;
  int bottom = obj2->getRightBottom().y;

  return ((topFirst + vec.y < bottom and bottomFirst + vec.y > top)
          and (rightFirst + vec.x > left and leftFirst + vec.x < right));
}


bool Handler::collistionWithEnemy(GameObject* player, std::vector<std::unique_ptr<GameObject>> &enemies, sf::Vector2f direction) {
  for(std::unique_ptr<GameObject>& enemy : enemies){
    if (collistionCourse(player, enemy.get(), direction)) {
      return true;
    }
  }
  return false;
}


void Handler::handleMovement(GameObject* player, std::vector<std::unique_ptr<GameObject>> &enemies) {
  if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) and player->getPosition().x > 0)
    and !collistionWithEnemy(player, enemies, sf::Vector2f(-this->movementSpeed, 0)))
  {
    player->move(sf::Vector2f(-this->movementSpeed, 0));
  }
  if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) and (player->getPosition().x + player->getTextureRect().width < width))
    and !collistionWithEnemy(player, enemies, sf::Vector2f(this->movementSpeed, 0)))
  {
    player->move(sf::Vector2f(this->movementSpeed, 0));
  }
  if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and player->getPosition().y > 0)
    and !collistionWithEnemy(player, enemies, sf::Vector2f(0, -this->movementSpeed)))
  {
    player->move(sf::Vector2f(0, -this->movementSpeed));
  }
  if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and (player->getPosition().y + player->getTextureRect().height) < height)
    and !collistionWithEnemy(player, enemies, sf::Vector2f(0, this->movementSpeed)))
  {
    player->move(sf::Vector2f(0, this->movementSpeed));
  }

}
