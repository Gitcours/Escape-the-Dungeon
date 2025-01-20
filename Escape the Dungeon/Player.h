#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "outils.h"

class Player : public Entity
{
private:

	float speed = 0.1f;

	bool isUp = false;
	bool isDown = false;
	bool isLeft = false;
	bool isRight = false;

	sf::Clock updateclock;
	sf::Time updatetime;

public:
	Player();
	sf::RectangleShape player;
	void init() override;
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	void movements();
	void handleInput(const sf::Event& event, sf::RenderWindow& window);
	std::string tag = "Player";
};

#endif
