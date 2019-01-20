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

  void move(sf::Vector2f vec);

  void setPosition(sf::Vector2f vec);

  void nullVelocity();

  void changeVelocity(double delta_v);

  void setVelocity(double v);

  sf::Texture texture;
  sf::Sprite sprite;
  double vertical_velocity;
};

#endif
