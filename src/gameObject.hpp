#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class GameObject {
public:
  GameObject(std::string filePath);

  GameObject();

  sf::Vector2f getLeftTop();

  sf::Vector2f getRightBottom();

  sf::Vector2f getPosition();

  sf::Vector2f getCenter();

  sf::IntRect getTextureRect();

  sf::Texture texture;
  sf::Sprite sprite;
};

class Player : public GameObject {
public:
  void changeVelocity(double delta_v);

  void setVelocity(double v);

  void increaseCounter(int dst);

  void resolveAnimation();

  std::vector<std::unique_ptr<sf::Texture>> textures;
  float vertical_velocity;
  int move_counter;
};

class Enemy : public GameObject {
public:
  void changeVelocity(double delta_v);

  void setVelocity(double v);

  void resolveAnimation();

  float vertical_velocity;
};

class EnvironmentalObject : public GameObject {};

#endif
