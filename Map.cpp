#include "Map.h"
Map::Map() {

}
/*
Gets the specific map element at the given row (r) and column (c)
*/
int Map::getMapElementAtIndex(int r, int c) {
	return this->m_Map[r][c];
}

void Map::populateMapElements(int toPop[20][20]) {
	for (int r = 0; r <= 20; r++) {
		for (int c = 0; c <= 20; c++) {
			switch (toPop[r][c]) {
			case 0:
				//load empty space
				break;
			case 1:
				//load platform
				break;
			case 2:
				//load moving platform
				break;
			}
		}
	}
}