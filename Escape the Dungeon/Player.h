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

	bool isinbound(sf::RectangleShape& sprite, int direction);

	sf::Clock updateclock;
	sf::Time updatetime;
	sf::Clock updatepotclock;
	sf::Time updatepottime;

public:
	Player();
	sf::RectangleShape player;

	bool haskey;

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	void handleInput(const sf::Event& event, sf::RenderWindow& window);
	void itemshandler(int item);
	void effecttimerupdate(float deltaTime);
	std::string tag = "Player";
};

#endif