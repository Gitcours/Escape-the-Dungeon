#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

#include "outils.h"

class Map {
public:
	Map(std::string mapfiledir);
	void draw(sf::RenderWindow& window);
	std::vector<sf::RectangleShape> walls;
	std::vector<sf::RectangleShape> door;
	std::vector<int> elements;

private:
	std::string line;
	std::ifstream mapfile;
};

#endif