#ifndef INTERACT_H
#define INTERACT_H

#include <SFML/Graphics.hpp>

class Interact
{
public:
	virtual void draw(sf::RenderWindow& window) = 0;
	std::string tag;
};
#endif