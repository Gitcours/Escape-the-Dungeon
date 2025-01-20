#include "Ennemis.h"


ChaserEnemy::ChaserEnemy(Player& _player) : player(&_player) {
	chaser.setSize(sf::Vector2f(50, 50));
	chaser.setFillColor(sf::Color::Red);
	chaser.setPosition(100, 100);
};

void ChaserEnemy::init()
{
}

void ChaserEnemy::brain()
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
}

void ChaserEnemy::update(float deltaTime)
{
	updatetime = sf::milliseconds(deltaTime);
	if (updateclock.getElapsedTime() >= updatetime)
	{
		brain();
		updateclock.restart();
	}
}

void ChaserEnemy::draw(sf::RenderWindow& window)
{
	window.draw(chaser);
}