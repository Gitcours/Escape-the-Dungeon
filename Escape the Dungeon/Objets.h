#ifndef OBJETS_H
#define OBJETS_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "outils.cpp"

class Objets : public Entity
{
private:

public:
	Objets();
	void init() override;
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	void handleInput(const sf::Event& event, sf::RenderWindow& window);
	std::string tag = "Objets";
};

#endif