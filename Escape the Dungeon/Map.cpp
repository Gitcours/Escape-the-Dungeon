#include "Map.h"

Map::Map() {
	mapfile.open("Assets/Map/1.txt");
	int y = 0;
	while (getline(mapfile, line)) {
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '#') {
				walls.push_back(sf::RectangleShape(sf::Vector2f(50, 50)));
				elements.push_back(1);
			}
			if (line[i] == '-') {
				door.push_back(sf::RectangleShape(sf::Vector2f(50, 50)));
				elements.push_back(2);
			}
			if (line[i] == ' ')
			{
				elements.push_back(0);
			}
		}
		y++;
		std::cout << std::endl;
	}
}

void Map::draw(sf::RenderWindow& window) {
	int w = 0;
	int d = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		if (elements[i] == 1)
		{
			walls[w].setPosition(i * walls[w].getSize().x, 0);
			window.draw(walls.at(w));
			w += 1;
		}
	}
}