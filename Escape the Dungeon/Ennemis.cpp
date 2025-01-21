#include "Ennemis.h"


ChaserEnemy::ChaserEnemy(Player& _player) : player(&_player) {
	chaser.setSize(sf::Vector2f(50, 50));
	chaser.setFillColor(sf::Color::Red);
	switch (int(gennbint(0,4)))
	{
	case 0:
		chaser.setPosition(-chaser.getSize().x, gennbint(0, windowSize.y));
		break;
	case 1:
		chaser.setPosition(windowSize.x, gennbint(0, windowSize.y));
		break;
	case 2:
		chaser.setPosition(gennbint(0, windowSize.x), -chaser.getSize().y);
		break;
	case 3:
		chaser.setPosition(gennbint(0, windowSize.x), windowSize.y);
		break;
	default:
		break;
	}
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

PatrollingEnemy::PatrollingEnemy() {
	Patrolling.setSize(sf::Vector2f(50, 50));
	Patrolling.setFillColor(sf::Color::Yellow);
	switch (int(gennbint(0, 4)))
	{
	case 0:
		Patrolling.setPosition(-Patrolling.getSize().x, gennbint(0, windowSize.y));
		direction = 0;
		break;
	case 1:
		Patrolling.setPosition(windowSize.x, gennbint(0, windowSize.y));
		direction = 1;
		break;
	case 2:
		Patrolling.setPosition(gennbint(0, windowSize.x), -Patrolling.getSize().y);
		direction = 2;
		break;
	case 3:
		Patrolling.setPosition(gennbint(0, windowSize.x), windowSize.y);
		direction = 3;
		break;
	default:
		break;
	}
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
			if (Patrolling.getPosition().x < 0)
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