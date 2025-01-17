#include "Player.h"

Player::Player(){};

void Player::update(float deltaTime) {
	if (isLeft) {
		player.move(-playerspeed, 0);
	}
	if (isRight) {
		player.move(playerspeed, 0);
	}
}

void Player::handleInput(const sf::Event& event, sf::RenderWindow& window) {
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		switch (event.key.code)
		{
		case Left:
			isLeft = true;
			break;
		case Right:
			isRight = true;
			break;
		case Jump:
			if (canJump) {
				std::cout << "Jump" << std::endl;
				canJump = false;
			}
			break;
		default:
			break;
		}
		break;
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
		case Left:
			isLeft = false;
			break;
		case Right:
			isRight = false;
			break;
		}
		break;
	}
}
void Player::draw(sf::RenderWindow& window) {
	window.draw(player);
}
