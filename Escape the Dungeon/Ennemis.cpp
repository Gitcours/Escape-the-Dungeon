#include "Ennemis.h"


ChaserEnemy::ChaserEnemy(Player& _player, sf::Vector2f posxy) : player(&_player) {
	chaser.setSize(sf::Vector2f(40, 40));
	chaser.setFillColor(sf::Color::Red);
	chaser.setPosition(posxy);
};

void ChaserEnemy::update(float deltaTime)
{
	updatetime = sf::milliseconds(deltaTime);
	if (updateclock.getElapsedTime() >= updatetime)
	{
		if (player->player.getPosition().x > chaser.getPosition().x)
		{
			chaser.move(speed, 0);
		}
		if (player->player.getPosition().x < chaser.getPosition().x)
		{
			chaser.move(-speed, 0);
		}
		if (player->player.getPosition().y > chaser.getPosition().y)
		{
			chaser.move(0, speed);
		}
		if (player->player.getPosition().y < chaser.getPosition().y)
		{
			chaser.move(0, -speed);
		}
		updateclock.restart();
	}
}

void ChaserEnemy::draw(sf::RenderWindow& window)
{
	window.draw(chaser);
}

PatrollingEnemy::PatrollingEnemy(sf::Vector2f posxy, int dir) : direction(dir) {
	Patrolling.setSize(sf::Vector2f(70, 70));
	Patrolling.setFillColor(sf::Color::Yellow);
	Patrolling.setPosition(posxy);
};

void PatrollingEnemy::update(float deltaTime)
{
	updatetime = sf::milliseconds(deltaTime);
	if (updateclock.getElapsedTime() >= updatetime)
	{
		switch (direction)
		{
		case 0:
			Patrolling.move(speed, 0);
			if (Patrolling.getPosition().x + Patrolling.getGlobalBounds().width > windowSize.x)
			{
				direction = 1;
			}
			break;
		case 1:
			Patrolling.move(-speed, 0);
			if (Patrolling.getPosition().x <= 0)
			{
				direction = 0;
			}
			break;
		case 2:
			Patrolling.move(0, speed);
			if (Patrolling.getPosition().y + Patrolling.getGlobalBounds().height > windowSize.y)
			{
				direction = 3;
			}
			break;
		case 3:
			Patrolling.move(0, -speed);
			if (Patrolling.getPosition().y < 0)
			{
				direction = 2;
			}
			break;
		default:
			break;
		}
		updateclock.restart();
	}
}

void PatrollingEnemy::draw(sf::RenderWindow& window)
{
	window.draw(Patrolling);
}