//#include "Map.h"
//
//Map::Map() {
//	mapfile.open("Assets/Map/1.txt");
//	string line;
//	int y = 0;
//
//	while (getline(mapfile, line)) {
//		for (int i = 0; i < line.size(); i++) {
//			if (line[i] == '#') {
//				walls.push_back(new RectangleShape(Vector2f(10, 10)));
//			}
//
//			if (line[i] == '-') {
//				door.push_back(new RectangleShape(Vector2f(10, 10)));
//			}
//		}
//		y++;
//		cout << endl;;
//
//	}
//
//}
//
