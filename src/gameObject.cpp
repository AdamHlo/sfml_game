#include "gameObject.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>

sf::Vector2f GameObject::getLeftTop() { return sprite.getPosition(); }

sf::Vector2f GameObject::getRightBottom() {
  return sf::Vector2f(sprite.getPosition().x + sprite.getTextureRect().width,
                      sprite.getPosition().y + sprite.getTextureRect().height);
}

sf::Vector2f GameObject::getCenter() {
  return sf::Vector2f(
      sprite.getPosition().x + sprite.getTextureRect().width / 2,
      sprite.getPosition().y + sprite.getTextureRect().height / 2);
}

sf::IntRect GameObject::getTextureRect() { return sprite.getTextureRect(); }

void GameObject::move(sf::Vector2f vec) { sprite.move(vec); }

void GameObject::setPosition(sf::Vector2f vec) { sprite.setPosition(vec); }

GameObject::GameObject(std::string filePath) {
  this->texture.loadFromFile(filePath);
  this->sprite.setTexture(texture);
}

GameObject::GameObject() {}

void Player::changeVelocity(double delta_v) {
  this->vertical_velocity += delta_v;
}

Player::Player() {
  this->texture.loadFromFile("data/p1.png");
  this->cycle_length = 40;
  this->sprite.setTexture(texture);
  this->textures.push_back(sf::Image());
  this->textures.push_back(sf::Image());
  this->textures.push_back(sf::Image());
  this->textures[0].loadFromFile("data/p1.png");
  this->textures[1].loadFromFile("data/p2.png");
  this->textures[2].loadFromFile("data/p3.png");
}

void Player::setVelocity(double v) { this->vertical_velocity = v; }

void Player::move(sf::Vector2f vec) {
  this->sprite.move(vec);
  if (this->vertical_velocity == 0) {
    this->move_counter += std::abs(static_cast<int>(vec.x));
    if (this->move_counter >= this->cycle_length) {
      this->move_counter = 0;
    }
  }
}

void Player::resolveAnimation() {
  unsigned int frames = this->textures.size();
  unsigned int frame_length = this->cycle_length / frames;
  unsigned int frame_no = this->move_counter / frame_length;
  this->texture.update(textures[frame_no]);
}

void Enemy::changeVelocity(double delta_v) {
  this->vertical_velocity += delta_v;
}

void Enemy::setVelocity(double v) { this->vertical_velocity = v; }
