#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "outils.h"

class Player : public Entity
{
private:

	float speed;
	float normalisation;
	float effecttimer;

	bool isUp;
	bool isDown;
	bool isLeft;
	bool isRight;

	bool isspeedpot;

	enum direction {
		up,
		down,
		left,
		right
	};

	bool isinbound(sf::RectangleShape& wallssprite, sf::RectangleShape& Playersprite, int direction);

	sf::Clock updateclock;
	sf::Time updatetime;
	sf::Clock updatepotclock;
	sf::Time updatepottime;
	sf::RenderWindow& window;
	std::vector<sf::RectangleShape>& wallsvector;

public:
	Player(sf::RenderWindow& windowref, std::vector<sf::RectangleShape>& wallsref, sf::Vector2f posxy);
	sf::RectangleShape player;

	bool haskey;

	void update(float deltaTime) override;
	void playerupdate(float deltaTime, std::vector<sf::RectangleShape>& wallsvector);
	void draw(sf::RenderWindow& window) override;
	void handleInput(const sf::Event& event);
	void itemshandler(int item);
	void effecttimerupdate(float deltaTime);
	std::string tag = "Player";
};

#endif