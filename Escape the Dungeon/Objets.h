#ifndef OBJETS_H
#define OBJETS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Interact.h"
#include "outils.h"

class SpeedPotion : public Interact
{
private:

public:
	SpeedPotion(sf::Vector2f posxy);
	~SpeedPotion();
	sf::RectangleShape spotion;
	void draw(sf::RenderWindow& window) override;
	std::string tag = "SpeedPotion";
};

class Key : public Interact
{
private:

public:
	Key(sf::Vector2f posxy);
	~Key();
	sf::RectangleShape key;
	void draw(sf::RenderWindow& window) override;
	std::string tag = "key";
};

#endif