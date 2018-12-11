#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class GameObject{

  public:

    GameObject(std::string filePath){

      this->texture.loadFromFile(filePath);
      this->sprite.setTexture(texture);

    }

    sf::Vector2f getLeftTop(){
      return sprite.getPosition();
    }

    sf::Vector2f getRightBottom(){
      return sf::Vector2f(sprite.getPosition().x + sprite.getTextureRect().width, sprite.getPosition().y + sprite.getTextureRect().height);
    }

    sf::Vector2f getPosition(){
      return sprite.getPosition();
    }

    sf::IntRect getTextureRect(){
      return sprite.getTextureRect();
    }

    void move(sf::Vector2f vec){
      sprite.move(vec);
    }

    void setPosition(sf::Vector2f vec){
      sprite.setPosition(vec);
    }

    sf::Texture texture;
    sf::Sprite sprite;

};
