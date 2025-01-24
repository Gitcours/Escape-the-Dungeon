#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include "Player.h"
#include "Ennemis.h"
#include "Map.h"
#include "Objets.h"

sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Escape the Dungeon");
sf::Event event;

std::unique_ptr<Map> map = std::make_unique<Map>("Assets/Map/1.txt");

std::vector<ChaserEnemy> chaser;
std::vector<PatrollingEnemy> patrolling;
std::vector<SpeedPotion> speedpotion;
std::vector<Key> key;

Player* player = new Player(window, map->walls, sf::Vector2f(windowSize.x/2, windowSize.y - 90));

const sf::Keyboard::Key Pause = sf::Keyboard::Escape;
sf::RectangleShape Pausemenu(sf::Vector2f(windowSize.x / 2, windowSize.y / 2));

bool playeralive = true;
bool playerwin = false;
bool isPaused = false;
bool canPause = true;

void init() {
	srand(time(NULL));
	gennbint(0, 0);
	gennbint(0, 0);
	gennbint(0, 0);

	Pausemenu.setFillColor(sf::Color(255, 255, 255, 0));
	Pausemenu.setPosition(sf::Vector2f(windowSize.x / 2 - Pausemenu.getSize().x / 2, windowSize.y / 2 - Pausemenu.getSize().y / 2));

	int y = 0;
	int x = 0;
	int c = 0;
	int p = 0;
	for (int i = 0; i < map->elements.size(); i++, x++)
	{
		if (i % int(windowSize.x / map->walls[0].getSize().x) == 0 && i != 0)
		{
			y += int(map->walls[0].getGlobalBounds().width);
			x = 0;
		}
		if (map->elements[i] == 3)
		{
			chaser.push_back(ChaserEnemy(*player, sf::Vector2f(x * 40, y)));
			c += 1;
		}
		if (map->elements[i] == 4)
		{
			switch (p)
			{
			case 0:
				patrolling.push_back(PatrollingEnemy(sf::Vector2f(x * 40, y), 0));
				break;
			case 1:
				patrolling.push_back(PatrollingEnemy(sf::Vector2f(x * 40, y), 1));
				break;
			case 2:
				patrolling.push_back(PatrollingEnemy(sf::Vector2f(x * 40, y), 0));
				break;
			default:
				break;
			}
			p += 1;
		}
		if (map->elements[i] == 5)
		{
			key.push_back(Key(sf::Vector2f(x * 40, y)));
		}
		if (map->elements[i] == 6)
		{
			speedpotion.push_back(SpeedPotion(sf::Vector2f(x * 40, y)));
		}
	}
}

void update() {
	player->playerupdate(2.f, map->walls);
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
	for (int i = 0; i < map->door.size(); i++)
	{
		if (map->door[i].getGlobalBounds().intersects(player->player.getGlobalBounds()) && player->haskey == true)
		{

			std::cout << "GG" << std::endl;
			playerwin = true;
		}
	}
}

void affichage() {
	window.clear(/*sf::Color::Black*/);
	player->draw(window);
	map->draw(window);
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
		if (playeralive && !isPaused && !playerwin)
		{
			update();
		}
		else if (playerwin)
		{
			player->player.setPosition(sf::Vector2f());
			map = std::make_unique<Map>("Assets/Map/2.txt");
			chaser.clear();
			patrolling.clear();
			key.clear();
			speedpotion.clear();
			init();
			playerwin = false;
		}
		affichage();
		while (window.pollEvent(event)) {
			player->handleInput(event);
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