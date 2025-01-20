#ifndef ENNEMIS_H
#define ENNEMIS_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class ChaserEnemy : public Entity
{
private:
	sf::RectangleShape chaser;

	float speed = 0.1f;
	Player* player;
	sf::Clock updateclock;
	sf::Time updatetime;

public:
	ChaserEnemy(Player& _player);

	void init() override;
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	void brain();
	std::string tag = "Chaser";

};

class PatrollingEnemy : public Entity
{
private:
	sf::RectangleShape chaser;

	float speed = 0.1f;

	sf::Clock updateclock;
	sf::Time updatetime;

public:
	PatrollingEnemy();

	void init() override;
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	std::string tag = "Patrolling";

};

#endif // !ENNEMIS_H
