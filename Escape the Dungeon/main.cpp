#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include "Player.h"
#include "Ennemis.h"
#include "Objets.h"

sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Escape the Dungeon");
sf::Event event;

Player* player = new Player();
std::vector<ChaserEnemy> chaser;
std::vector<PatrollingEnemy> patrolling;
std::vector<SpeedPotion> speedpotion;


const sf::Keyboard::Key Pause = sf::Keyboard::Escape;

bool playeralive = true;
bool isPaused = false;
bool canPause = false;

void init() {
	for (int i = 0; i < 10; i++)
	{
		chaser.push_back(ChaserEnemy(*player));
	}

	for (int i = 0; i < 5; i++)
	{
		patrolling.push_back(PatrollingEnemy());
	}
	for (int i = 0; i < 1; i++)
	{
		speedpotion.push_back(SpeedPotion());
	}
}

void update() {
	player->update(2.f);
	player->potiontimerupdate(2.f);
	for (int i = 0; i < chaser.size(); i++)
	{
		if (chaser[i].chaser.getGlobalBounds().intersects(player->player.getGlobalBounds()))
		{
			std::cout << "Game Over" << std::endl;
			playeralive = false;
		}
		else
		{
			chaser[i].update(2.5f);
		}
	}
	for (int i = 0; i < patrolling.size(); i++)
	{
		if (patrolling[i].Patrolling.getGlobalBounds().intersects(player->player.getGlobalBounds()))
		{
			std::cout << "Game Over" << std::endl;

			playeralive = false;
		}
		else
		{
			patrolling[i].update(2.5f);
		}
	}
	for (int i = 0; i < speedpotion.size(); i++)
	{
		if (speedpotion[i].spotion.getGlobalBounds().intersects(player->player.getGlobalBounds()))
		{
			player->potionhandler(0);
			speedpotion.erase(speedpotion.begin() + i);
		}
		else
		{
			speedpotion[i].update(2.5f);
		}
	}
}

void affichage() {
	window.clear(/*sf::Color::Black*/);
	player->draw(window);
	for (int i = 0; i < chaser.size(); i++)
	{
		chaser[i].draw(window);
	}
	for (int i = 0; i < patrolling.size(); i++)
	{
		patrolling[i].draw(window);
	}
	for (int i = 0; i < speedpotion.size(); i++)
	{
		speedpotion[i].draw(window);
	}
	window.display();
}

int main() {
	init();
	while (window.isOpen()) {
		if (playeralive)
		{
			update();
			affichage();
		}
		while (window.pollEvent(event)) {
			player->handleInput(event, window);
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