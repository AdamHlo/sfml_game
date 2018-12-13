#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

class GameObject{

public:

  GameObject(std::string filePath);

  GameObject();

  sf::Vector2f getLeftTop();

  sf::Vector2f getRightBottom();

  sf::Vector2f getPosition();

  sf::IntRect getTextureRect();

  void move(sf::Vector2f vec);

  void setPosition(sf::Vector2f vec);

  std::shared_ptr<sf::Texture> texture;
  std::shared_ptr<sf::Sprite> sprite;

};

#endif
