#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include "Player.h"
#include "Ennemis.h"
#include "Map.h"
#include "Objets.h"

sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Escape the Dungeon");
sf::Event event;

Player* player = new Player();
Map map;
std::vector<ChaserEnemy> chaser;
std::vector<PatrollingEnemy> patrolling;
std::vector<SpeedPotion> speedpotion;
std::vector<Key> key;


const sf::Keyboard::Key Pause = sf::Keyboard::Escape;
sf::RectangleShape Pausemenu(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));

bool playeralive = true;
bool isPaused = false;
bool canPause = true;

void init() {
	srand(time(NULL));
	gennbint(0, 0);
	gennbint(0, 0);
	gennbint(0, 0);

	Pausemenu.setFillColor(sf::Color(255, 255, 255, 0));
	Pausemenu.setPosition(sf::Vector2f(windowSize.x / 2 - Pausemenu.getSize().x / 2, windowSize.y / 2 - Pausemenu.getSize().y / 2));

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
	for (int i = 0; i < 1; i++)
	{
		key.push_back(Key());
	}
}

void update() {
	player->update(2.f);
	player->effecttimerupdate(1000.f);
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
			player->itemshandler(0);
			speedpotion.erase(speedpotion.begin() + i);
		}
	}
	for (int i = 0; i < key.size(); i++)
	{
		if (key[i].key.getGlobalBounds().intersects(player->player.getGlobalBounds())) 
		{
			player->itemshandler(1);
			key.erase(key.begin() + i);
		}
	}
}

void affichage() {
	window.clear(/*sf::Color::Black*/);
	player->draw(window);
	map.draw(window);
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
	for (int i = 0; i < key.size(); i++)
	{
		key[i].draw(window);
	}
	window.draw(Pausemenu);
	window.display();
}

int main() {
	init();
	while (window.isOpen()) {
		if (playeralive && !isPaused)
		{
			update();
		}
		affichage();
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
						isPaused = !isPaused;
						canPause = false;
						if (isPaused)
						{
							Pausemenu.setFillColor(sf::Color(255, 255, 255, 255));
						}
						else
						{
							Pausemenu.setFillColor(sf::Color(255, 255, 255, 0));
						}
					}
					break;
				default:
					break;
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case Pause:
					canPause = true;
					break;
				default:
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