#include "Map.h"

Map::Map(std::string mapfiledir) {
	mapfile.open(mapfiledir);
	int y = 0;
	while (getline(mapfile, line)) {
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == ' ')
			{
				elements.push_back(0);
			}
			if (line[i] == '#') {
				walls.push_back(sf::RectangleShape(sf::Vector2f(40, 40)));
				elements.push_back(1);
			}
			if (line[i] == '-') {
				door.push_back(sf::RectangleShape(sf::Vector2f(40, 40)));
				elements.push_back(2);
			}
			if (line[i] == 'c')
			{
				elements.push_back(3);
			}
			if (line[i] == 'p')
			{
				elements.push_back(4);
			}
			if (line[i] == 'k')
			{
				elements.push_back(5);
			}
			if (line[i] == 's')
			{
				elements.push_back(6);
			}
		}
		y++;
		std::cout << std::endl;
	}
}

void Map::draw(sf::RenderWindow& window) {
	int y = 0;
	int x = 0;

	int w = 0;
	int d = 0;
	for (int i = 0; i < elements.size(); i++, x++)
	{
		if (i % int(windowSize.x / walls[0].getSize().x) == 0 && i != 0)
		{
			y += int(walls[0].getGlobalBounds().width);
			x = 0;
		}
		if (elements[i] == 1)
		{
			walls[w].setPosition(x * walls[w].getSize().x, y);
			window.draw(walls.at(w));
			w += 1;
		}
		if (elements[i] == 2)
		{
			door[d].setFillColor(sf::Color::Cyan);
			door[d].setPosition(x * door[d].getSize().x, y);
			window.draw(door.at(d));
			d += 1;
		}
	}
}