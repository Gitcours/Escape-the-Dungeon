#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include "Player.h"

extern sf::RenderWindow window(sf::VideoMode(800, 600), "Escape the Dungeon");
sf::Event event;

Player player;

const sf::Keyboard::Key Pause = sf::Keyboard::Escape;

bool isPaused = false;
bool canPause = false;



void init() {
	//player.setPosition(windowSize.x / 2, windowSize.y / 2);
}

void update() {
	player.update(0.1f);
}

void affichage() {
	window.clear(/*sf::Color::Black*/);
	player.draw(window);
	window.display();
}

int main() {
	init();
	while (window.isOpen()) {
		update();
		affichage();
		while (window.pollEvent(event)) {
			player.handleInput(event, window);
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case Pause:
					if (canPause)
					{
						std::cout << "Pause" << std::endl;
						isPaused = !isPaused;
						canPause = false;
					}
					break;
				default:
					break;
				}
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case Pause:
					canPause = true;
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
	}
}