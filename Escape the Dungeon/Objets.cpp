#include "Objets.h"

SpeedPotion::SpeedPotion() {
	spotion.setSize(sf::Vector2f(20, 20));
	spotion.setFillColor(sf::Color::Blue);
	spotion.setPosition(gennbint(0, windowSize.x), gennbint(0, windowSize.y));
};

SpeedPotion::~SpeedPotion() {
	std::cout << "SpeedPotion detruit" << std::endl;
}

void SpeedPotion::update(float deltaTime) {
	updatetime = sf::milliseconds(deltaTime);
	if (updateclock.getElapsedTime() >= updatetime)
	{
		updateclock.restart();
	}
}

void SpeedPotion::draw(sf::RenderWindow& window) {
	window.draw(spotion);
}