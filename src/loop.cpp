#include "gameTable.hpp"
#include "handler.hpp"
#include "loop.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

void Loop::run() {
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(1600, 900), "Game");
  // initialize view
  sf::View view;
  view.reset(sf::FloatRect(0, 0, 1600, 900));
  // Load game sprites
  GameTable table = GameTable();
  // Load a music to play
  sf::Music music;
  music.openFromFile("data/8bitmusic.ogg");
  // Play the music
  music.setLoop(true);
  music.play();
  table.player->setPosition(sf::Vector2f(1600, 1000));
  table.gameObjects[0]->setPosition(sf::Vector2f(1100, 1180));
  table.gameObjects[1]->setPosition(sf::Vector2f(1500, 1300));
  table.gameObjects[2]->setPosition(sf::Vector2f(1800, 970));
  table.gameObjects[3]->setPosition(sf::Vector2f(1000, 945));
  table.gameObjects[4]->setPosition(sf::Vector2f(1250, 700));
  table.gameObjects[5]->setPosition(sf::Vector2f(1350, 500));
  table.gameObjects[6]->setPosition(sf::Vector2f(700, 700));
  table.gameObjects[7]->setPosition(sf::Vector2f(2000, 750));
  table.gameObjects[8]->setPosition(sf::Vector2f(2200, 550));
  table.gameObjects[9]->setPosition(sf::Vector2f(1500, 350));

  sf::Texture background;
  sf::Sprite background_sprite;
  background.loadFromFile("data/gameBackgroundNew.png");
  background_sprite.setTexture(background);

  Handler handler =
      Handler(background.getSize().x, background.getSize().y, -11570, 2600);

  sf::Time t = sf::milliseconds(5);
  sf::Clock clock;

  while (window.isOpen()) {

    sf::sleep(t);
    // Process events
    sf::Event event;

    while (window.pollEvent(event)) {
      // Close window: exit
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear();
    sf::Vector2f direction = handler.getMovementInput();
    handler.handleJump(table.player.get());
    handler.handleMovement(table.player.get(), table.gameObjects, direction,
                           t.asSeconds());
    view.setCenter(table.player->getCenter());

    window.setView(view);
    window.draw(background_sprite);
    window.draw(table.gameObjects[0]->sprite);
    window.draw(table.gameObjects[1]->sprite);
    window.draw(table.gameObjects[2]->sprite);
    window.draw(table.gameObjects[3]->sprite);
    window.draw(table.gameObjects[4]->sprite);
    window.draw(table.gameObjects[5]->sprite);
    window.draw(table.gameObjects[6]->sprite);
    window.draw(table.gameObjects[7]->sprite);
    window.draw(table.gameObjects[8]->sprite);
    window.draw(table.gameObjects[9]->sprite);
    window.draw(table.player->sprite);
    window.display();
  }
}
