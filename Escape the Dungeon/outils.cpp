#include "outils.h"

const sf::Keyboard::Key Up = sf::Keyboard::Z;
const sf::Keyboard::Key Down = sf::Keyboard::S;
const sf::Keyboard::Key Left = sf::Keyboard::Q;
const sf::Keyboard::Key Right = sf::Keyboard::D;

const sf::Vector2f windowSize(1280, 960);

float gennbint(int nb1, int nb2) {
    return floor(nb1 + ((rand() / (float)RAND_MAX) * nb2));
}