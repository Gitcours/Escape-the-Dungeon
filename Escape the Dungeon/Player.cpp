#include "Player.h"

Player::Player(sf::RenderWindow& windowref, std::vector<sf::RectangleShape>& wallsref, sf::Vector2f posxy)
	: isUp(false), isDown(false), isLeft(false), isRight(false), speed(1.f), normalisation(std::sqrt(2)), effecttimer(0), haskey(false), window(windowref), wallsvector(wallsref)
{
	player.setSize(sf::Vector2f(30, 30));
	player.setFillColor(sf::Color::Green);
	player.setPosition(posxy);
};

bool Player::isinbound(sf::RectangleShape& wallssprite, sf::RectangleShape& playersprite, int direction) {
	sf::RectangleShape playerBounds(sf::Vector2f(playersprite.getGlobalBounds().width, playersprite.getGlobalBounds().height));
	sf::RectangleShape wallBounds(sf::Vector2f(wallssprite.getGlobalBounds().width, wallssprite.getGlobalBounds().height));

	wallBounds.setPosition(wallssprite.getPosition().x, wallssprite.getPosition().y);

	switch (direction) {
	case direction::up:
		playerBounds.setPosition(playersprite.getPosition().x, playersprite.getPosition().y - speed);
		break;
	case direction::down:
		playerBounds.setPosition(playersprite.getPosition().x, playersprite.getPosition().y + speed);
		break;
	case direction::left:
		playerBounds.setPosition(playersprite.getPosition().x - speed, playersprite.getPosition().y);
		break;
	case direction::right:
		playerBounds.setPosition(playersprite.getPosition().x + speed, playersprite.getPosition().y);
		break;
	default:
		return false;
	}
	return playerBounds.getGlobalBounds().intersects(wallBounds.getGlobalBounds());
}

void Player::itemshandler(int item) {
	switch (item)
	{
	case 0:
		effecttimer = 5.f;
		speed *= 2;
		isspeedpot = true;
		break;
	case 1:
		haskey = true;
		break;
	default:
		break;
	}
}

void Player::effecttimerupdate(float deltaTime){

	updatepottime = sf::milliseconds(deltaTime);

	if (updatepotclock.getElapsedTime() >= updatepottime)
	{
		updatepotclock.restart();
		if (isspeedpot)
		{
			if (effecttimer > 0)
			{
				effecttimer -= 1;
			}
			else
			{
				isspeedpot = false;
				speed /= 2;
			}
		}
	}
}

void Player::update(float deltaTime) {}

void Player::playerupdate(float deltaTime, std::vector<sf::RectangleShape>& wallsref) {

	updatetime = sf::milliseconds(deltaTime);

	if (updateclock.getElapsedTime() >= updatetime)
	{
		updateclock.restart();
		wallsvector = wallsref;
		if ((isUp && !isDown && !isLeft && !isRight) || (isLeft && isRight && isUp && !isDown))
		{
			bool tempval = true;
			for (int i = 0; i < wallsvector.size(); i++)
			{
				if (isinbound(wallsvector[i], player, direction::up))
				{
					tempval = false;
					break;
				}
			}
			if (tempval)
			{
				player.move(0, -speed);
			}
		}
		if ((isDown && !isUp && !isLeft && !isRight) || (isLeft && isRight && !isUp && isDown))
		{
			bool tempval = true;
			for (int i = 0; i < wallsvector.size(); i++)
			{
				if (isinbound(wallsvector[i], player, direction::down))
				{
					tempval = false;
					break;
				}
			}

			if (tempval)
			{
				player.move(0, speed);
			}
		}
		if ((isLeft && !isRight && !isUp && !isDown) || (isUp && isDown && isLeft && !isRight))
		{
			bool tempval = true;
			for (int i = 0; i < wallsvector.size(); i++)
			{
				if (isinbound(wallsvector[i], player, direction::left))
				{
					tempval = false;
					break;
				}
			}
			if (tempval)
			{
				player.move(-speed, 0);
			}
		}
		if ((isRight && !isLeft && !isUp && !isDown) || (isUp && isDown && !isLeft && isRight))
		{
			bool tempval = true;
			for (int i = 0; i < wallsvector.size(); i++)
			{
				if (isinbound(wallsvector[i], player, direction::right))
				{
					tempval = false;
					break;
				}
			}
			if (tempval)
			{
				player.move(speed, 0);
			}
		}
		if (isUp && isLeft && !isDown && !isRight)
		{
			bool tempval = true;
			for (int i = 0; i < wallsvector.size(); i++)
			{
				if (isinbound(wallsvector[i], player, direction::up))
				{
					tempval = false;
					break;
				}
			}
			if (tempval)
			{
				player.move(0, -speed / normalisation);
			}

			bool tempvalb = true;
			for (int i = 0; i < wallsvector.size(); i++)
			{
				if (isinbound(wallsvector[i], player, direction::left))
				{
					tempvalb = false;
					break;
				}
			}
			if (tempvalb)
			{
				player.move(-speed / normalisation, 0);
			}
		}
		if (isUp && isRight && !isDown && !isLeft)
		{
			bool tempval = true;
			for (int i = 0; i < wallsvector.size(); i++)
			{
				if (isinbound(wallsvector[i], player, direction::up))
				{
					tempval = false;
					break;
				}
			}
			if (tempval)
			{
				player.move(0, -speed / normalisation);
			}

			bool tempvalb = true;
			for (int i = 0; i < wallsvector.size(); i++)
			{
				if (isinbound(wallsvector[i], player, direction::right))
				{
					tempvalb = false;
					break;
				}
			}
			if (tempvalb)
			{
				player.move(speed / normalisation, 0);
			}
		}
		if (isDown && isLeft && !isUp && !isRight)
		{
			bool tempval = true;
			for (int i = 0; i < wallsvector.size(); i++)
			{
				if (isinbound(wallsvector[i], player, direction::down))
				{
					tempval = false;
					break;
				}
			}
			if (tempval)
			{
				player.move(0, speed / normalisation);
			}

			bool tempvalb = true;
			for (int i = 0; i < wallsvector.size(); i++)
			{
				if (isinbound(wallsvector[i], player, direction::left))
				{
					tempvalb = false;
					break;
				}
			}
			if (tempvalb)
			{
				player.move(-speed / normalisation, 0);
			}
		}
		if (isDown && isRight && !isUp && !isLeft)
		{
			bool tempval = true;
			for (int i = 0; i < wallsvector.size(); i++)
			{
				if (isinbound(wallsvector[i], player, direction::down))
				{
					tempval = false;
					break;
				}
			}
			if (tempval)
			{
				player.move(0, speed / normalisation);
			}

			bool tempvalb = true;
			for (int i = 0; i < wallsvector.size(); i++)
			{
				if (isinbound(wallsvector[i], player, direction::right))
				{
					tempvalb = false;
					break;
				}
			}
			if (tempvalb)
			{
				player.move(speed / normalisation, 0);
			}
		}
	}
}

void Player::handleInput(const sf::Event& event) {
	switch (event.type) {
	case sf::Event::KeyPressed:
		switch (event.key.code) {
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
		switch (event.key.code) {
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
