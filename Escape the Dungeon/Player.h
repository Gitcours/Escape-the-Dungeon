#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "outils.h"

class Player : public Entity
{
private:

	float speed = 0.5f;
	float normalisation = std::sqrt(2);
	float potiontimer = 0;

	bool isUp = false;
	bool isDown = false;
	bool isLeft = false;
	bool isRight = false;

	bool isspeedpot = false;

	enum direction {
		up,
		down,
		left,
		right
	};

	bool isinbound(sf::RectangleShape sprite, int direction);

	sf::Clock updateclock;
	sf::Time updatetime;

public:
	Player();
	sf::RectangleShape player;

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	void handleInput(const sf::Event& event, sf::RenderWindow& window);
	void potionhandler(int potion);
	void potiontimerupdate(float deltaTime);
	std::string tag = "Player";
};

#endif