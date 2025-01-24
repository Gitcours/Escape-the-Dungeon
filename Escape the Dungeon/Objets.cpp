#include "Objets.h"

SpeedPotion::SpeedPotion(sf::Vector2f posxy) {
	spotion.setSize(sf::Vector2f(20, 20));
	spotion.setFillColor(sf::Color::Blue);
	spotion.setPosition(posxy);
};

SpeedPotion::~SpeedPotion() {
}

void SpeedPotion::draw(sf::RenderWindow& window) {
	window.draw(spotion);
}

Key::Key(sf::Vector2f posxy) {
	key.setSize(sf::Vector2f(20, 20));
	key.setFillColor(sf::Color::Magenta);
	key.setPosition(posxy);
}

Key::~Key() {
}

void Key::draw(sf::RenderWindow& window) {
	window.draw(key);
}