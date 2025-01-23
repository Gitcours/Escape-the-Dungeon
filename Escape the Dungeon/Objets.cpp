#include "Objets.h"

SpeedPotion::SpeedPotion() {
	spotion.setSize(sf::Vector2f(20, 20));
	spotion.setFillColor(sf::Color::Blue);
	spotion.setPosition(gennbint(0, windowSize.x), gennbint(0, windowSize.y));
};

SpeedPotion::~SpeedPotion() {
}

void SpeedPotion::draw(sf::RenderWindow& window) {
	window.draw(spotion);
}

Key::Key() {
	key.setSize(sf::Vector2f(20, 20));
	key.setFillColor(sf::Color::Magenta);
	key.setPosition(gennbint(0, windowSize.x), gennbint(0, windowSize.y));
}

Key::~Key() {
}

void Key::draw(sf::RenderWindow& window) {
	window.draw(key);
}