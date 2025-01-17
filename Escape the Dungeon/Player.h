#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "outils.cpp"

class Player : public Entity
{
private:
	sf::RectangleShape player;

	float playerspeed = 0.1f;

	bool isLeft = false;
	bool isRight = false;

	bool canJump = false;

public:
	Player();

	void init() override;
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	void handleInput(const sf::Event& event, sf::RenderWindow& window);
};

#endif
