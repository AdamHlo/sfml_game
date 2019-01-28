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

  void move(sf::Vector2f vec);

  void setPosition(sf::Vector2f vec);

  sf::Vector2f getRightBottom();

  sf::Vector2f getPosition();

  sf::Vector2f getCenter();

  sf::IntRect getTextureRect();

  sf::Texture texture;
  sf::Sprite sprite;
};

class Player : public GameObject {
public:
  Player();

  void changeVelocity(double delta_v);

  void setVelocity(double v);

  void move(sf::Vector2f vec);

  void resolveAnimation();

  std::vector<sf::Image> textures;
  float vertical_velocity;
  int cycle_length;
  int move_counter;
};

class Enemy : public GameObject {
public:
  void changeVelocity(double delta_v);

  void setVelocity(double v);

  void resolveAnimation();

  float vertical_velocity;
};

class EnvironmentalObject : public GameObject {
public:
  bool moving;
};

#endif // ifndef GAMEOBJECT_H
