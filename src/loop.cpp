#include "objects.cpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "handler.cpp"

class Loop{

public:
  void run(){
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Game");
    // Load a player sprite to display

    // Load a music to play
    sf::Music music;
    music.openFromFile("data/8bitmusic.ogg");
    // Play the music
    music.setLoop(true);
    music.play();
    player.setPosition(sf::Vector2f(800, 450));
    spaceship.setPosition(sf::Vector2f(200, 200));
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



      window.draw(player.sprite);
      window.draw(spaceship.sprite);
      window.display();
    }

  }

}
