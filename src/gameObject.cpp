#include "gameObject.hpp"
#include <SFML/Graphics.hpp>
#include <string>

sf::Vector2f GameObject::getLeftTop()
{
  return sprite.getPosition();
}

sf::Vector2f GameObject::getRightBottom()
{
  return sf::Vector2f(sprite.getPosition().x + sprite.getTextureRect().width,
                      sprite.getPosition().y + sprite.getTextureRect().height);
}

sf::Vector2f GameObject::getCenter()
{
  return sf::Vector2f(
    sprite.getPosition().x + sprite.getTextureRect().width / 2,
    sprite.getPosition().y + sprite.getTextureRect().height / 2);
}

sf::IntRect GameObject::getTextureRect()
{
  return sprite.getTextureRect();
}

void GameObject::move(sf::Vector2f vec)
{
  sprite.move(vec);
}

void GameObject::setPosition(sf::Vector2f vec)
{
  sprite.setPosition(vec);
}

GameObject::GameObject(std::string filePath)
{
  this->texture.loadFromFile(filePath);
  this->sprite.setTexture(texture);
}

GameObject::GameObject() {}


void Player::changeVelocity(double delta_v)
{
  this->vertical_velocity += delta_v;
}

void Player::setVelocity(double v)
{
  this->vertical_velocity = v;
}

void Enemy::changeVelocity(double delta_v)
{
  this->vertical_velocity += delta_v;
}

void Enemy::setVelocity(double v)
{
  this->vertical_velocity = v;
}
