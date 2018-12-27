#include "loop.hpp"
#include "gameTable.hpp"
#include "handler.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

void Loop::run(){
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(1600, 900), "Game");
  // Load game sprites
  GameTable table = GameTable();
  // Load a music to play
  sf::Music music;
  music.openFromFile("data/8bitmusic.ogg");
  // Play the music
  music.setLoop(true);
  music.play();
  table.player->setPosition(sf::Vector2f(800, 450));
  table.enemies[0]->setPosition(sf::Vector2f(200, 200));
  table.enemies[1]->setPosition(sf::Vector2f(1200, 350));

  Handler handler = Handler();

  sf::Time t = sf::milliseconds(5);
  sf::Clock clock;


  while (window.isOpen()){

    sf::sleep(t);
    // Process events
    sf::Event event;

    while (window.pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed)
            window.close();
    }
    window.clear();

    handler.handleMovement(table.player.get(), table.enemies);

    window.draw(*table.player->sprite);
    window.draw(*table.enemies[0]->sprite);
    window.draw(*table.enemies[1]->sprite);
    window.display();

  }

}
