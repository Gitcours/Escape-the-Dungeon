#include "Player.h"

Player::Player(){
	player.setSize(sf::Vector2f(50, 50));
	player.setFillColor(sf::Color::Green);
	player.setPosition(windowSize.x/2, windowSize.y/2);
};

bool Player::isinbound(sf::RectangleShape sprite, int direction) {
	switch (direction)
	{
	case direction::up:
		return sprite.getPosition().y > 0;
		break;
	case direction::down:
		return sprite.getPosition().y < windowSize.y - sprite.getSize().y;
		break;
	case direction::left:
		return sprite.getPosition().x > 0;
		break;
	case direction::right:
		return sprite.getPosition().x < windowSize.x - sprite.getSize().x;
		break;
	default:
		return false;
		break;
	}
}

void Player::potionhandler(int potion) {
	switch (potion)
	{
	case 0:
		potiontimer = 5.f;
		speed *= 2;
		isspeedpot = true;
		break;
	default:
		break;
	}
}

void Player::potiontimerupdate(float deltaTime)
{
	updatetime = sf::milliseconds(deltaTime);
	if (updateclock.getElapsedTime() >= updatetime)
	{
		updateclock.restart();
		if (isspeedpot)
		{
			if (potiontimer > 0)
			{
				std::cout << potiontimer << std::endl;
				potiontimer -= 1;
			}
			else
			{
				std::cout << "STOP";
				isspeedpot = false;
				speed /= 2;
			}
		}
	}
}

void Player::update(float deltaTime) {
	updatetime = sf::milliseconds(deltaTime);

	if (updateclock.getElapsedTime() >= updatetime)
	{
		updateclock.restart();
		if ((isUp && !isDown && !isLeft && !isRight) || (isLeft && isRight && isUp && !isDown))
		{
			if (isinbound(player, direction::up))
			{
				player.move(0, -speed);
			}
		}
		if ((isDown && !isUp && !isLeft && !isRight) || (isLeft && isRight && !isUp && isDown))
		{
			if (isinbound(player, direction::down))
			{
				player.move(0, speed);
			}
		}
		if ((isLeft && !isRight && !isUp && !isDown) || (isUp && isDown && isLeft && !isRight))
		{
			if (isinbound(player, direction::left))
			{
				player.move(-speed, 0);
			}
		}
		if ((isRight && !isLeft && !isUp && !isDown) || (isUp && isDown && !isLeft && isRight))
		{
			if (isinbound(player, direction::right))
			{
				player.move(speed, 0);
			}
		}
		if (isUp && isLeft && !isDown && !isRight)
		{
			if (isinbound(player, direction::up))
			{
				player.move(0, -speed / normalisation);
			}
			if (isinbound(player, direction::left))
			{
				player.move(-speed / normalisation, 0);
			}
		}
		if (isUp && isRight && !isDown && !isLeft)
		{
			if (isinbound(player, direction::up))
			{
				player.move(0, -speed / normalisation);
			}
			if (isinbound(player, direction::right))
			{
				player.move(speed / normalisation, 0);
			}
		}
		if (isDown && isLeft && !isUp && !isRight)
		{
			if (isinbound(player, direction::down))
			{
				player.move(0, speed / normalisation);
			}
			if (isinbound(player, direction::left))
			{
				player.move(-speed / normalisation, 0);
			}
		}
		if (isDown && isRight && !isUp && !isLeft)
		{
			if (isinbound(player, direction::down))
			{
				player.move(0, speed / normalisation);
			}
			if (isinbound(player, direction::right))
			{
				player.move(speed / normalisation, 0);
			}
		}
	}
}

void Player::handleInput(const sf::Event& event, sf::RenderWindow& window) {
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		switch (event.key.code)
		{
		case sf::Keyboard::Z:
			isUp = true;
			break;
		case sf::Keyboard::S:
			isDown = true;
			break;
		case sf::Keyboard::Q:
			isLeft = true;
			break;
		case sf::Keyboard::D:
			isRight = true;
			break;
		default:
			break;
		}
		break;
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case sf::Keyboard::Z:
			isUp = false;
			break;
		case sf::Keyboard::S:
			isDown = false;
			break;
		case sf::Keyboard::Q:
			isLeft = false;
			break;
		case sf::Keyboard::D:
			isRight = false;
			break;
		}
		break;
	}
}
void Player::draw(sf::RenderWindow& window) {
	window.draw(player);
}
