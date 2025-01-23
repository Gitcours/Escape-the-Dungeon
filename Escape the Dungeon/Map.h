#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

class Map {
public:
	Map();
	void draw(sf::RenderWindow& window);
private:
	std::vector<int> elements;
	std::string line;
	std::ifstream mapfile;
	std::vector<sf::RectangleShape> walls;
	std::vector<sf::RectangleShape> door;
};

#endif