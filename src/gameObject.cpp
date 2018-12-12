#include <SFML/Graphics.hpp>
#include "gameObject.hpp"
#include <string>

sf::Vector2f  GameObject::getLeftTop(){

  return sprite->getPosition();

}


sf::Vector2f  GameObject::getRightBottom(){

  return sf::Vector2f(sprite->getPosition().x + sprite->getTextureRect().width, sprite->getPosition().y + sprite->getTextureRect().height);

}


sf::Vector2f  GameObject::getPosition(){

  return sprite->getPosition();

}


sf::IntRect GameObject::getTextureRect(){

  return sprite->getTextureRect();

}

void GameObject::move(sf::Vector2f vec){

  sprite->move(vec);

}


void GameObject::setPosition(sf::Vector2f vec){

  sprite->setPosition(vec);

}


GameObject::GameObject(std::string filePath) {

  this->texture->loadFromFile(filePath);
  this->sprite->setTexture(texture);

}

GameObject::GameObject(){}
