#ifndef OBJETS_H
#define OBJETS_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "outils.h"

class SpeedPotion : public Entity
{
private:

public:
	SpeedPotion();
	~SpeedPotion();
	sf::RectangleShape spotion;
	void interact(Player& _player);
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	std::string tag = "SpeedPotion";
};

#endif