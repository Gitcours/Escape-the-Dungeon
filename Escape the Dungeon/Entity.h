#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
public:
	virtual void init() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow & window) = 0;
};

#endif
