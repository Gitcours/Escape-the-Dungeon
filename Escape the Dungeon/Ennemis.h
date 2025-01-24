#ifndef ENNEMIS_H
#define ENNEMIS_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class ChaserEnemy : public Entity
{
private:
	float speed = 0.1f;
	Player* player;
	sf::Clock updateclock;
	sf::Time updatetime;

public:
	ChaserEnemy(Player& _player, sf::Vector2f posxy);

	sf::RectangleShape chaser;
	std::string tag = "Chaser";

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
};

class PatrollingEnemy : public Entity
{
private:
	float speed = 0.1f;
	int direction = 0;

	sf::Clock updateclock;
	sf::Time updatetime;

public:
	PatrollingEnemy(sf::Vector2f posxy, int dir);

	sf::RectangleShape Patrolling;
	std::string tag = "Patrolling";

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
};

#endif // !ENNEMIS_H
