#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class GameObject{

public:

  GameObject(std::string filePath);

  sf::Vector2f getLeftTop();

  sf::Vector2f getRightBottom();

  sf::Vector2f getPosition();

  sf::IntRect getTextureRect();

  void move(sf::Vector2f vec);

  void setPosition(sf::Vector2f vec);

  sf::Texture texture;
  sf::Sprite sprite;

};

#endif
