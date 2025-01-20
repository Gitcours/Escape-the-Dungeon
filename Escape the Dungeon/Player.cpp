#include "Player.h"

Player::Player(){
	player.setSize(sf::Vector2f(50, 50));
	player.setFillColor(sf::Color::Green);
	player.setPosition(400, 300);
};

void Player::init() {
//	player.setSize(sf::Vector2f(50, 50));
//	player.setFillColor(sf::Color::Green);
//	player.setPosition(400, 300);
}

void Player::update(float deltaTime) {
	updatetime = sf::milliseconds(deltaTime);
	if (updateclock.getElapsedTime() >= updatetime)
	{
		updateclock.restart();
		if (isUp)
		{
			player.move(0, -speed);
		}
		if (isDown)
		{
			player.move(0, speed);
		}
		if (isLeft) {
			player.move(-speed, 0);
		}
		if (isRight) {
			player.move(speed, 0);
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
