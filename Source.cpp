/*
Includes
*/
#include "Game.h"
#include <iostream>
#include "Character.hpp"
#include "defines.h"
#include "Map.h"

/*
Namespaces
*/
using namespace std;
using namespace integra;
using namespace main;

bool m_bGameRunning = true;

int main(int argc, char* argv[]) {
	Game* g = new Game();
	Map* m = new Map();
	g->init("Integra Engine", center, center, /*Width->*/g->SCREEN_WIDTH, /*Height->*/g->SCREEN_HEIGHT);
	//std::cout << c->getHP()->getCurrentHealth() << end
	cout << m->getMapElementAtIndex(1, 0) << endl;
	while (m_bGameRunning) {
		m_bGameRunning = g->getInputHandler()->getRunningState();
		g->render();	
		g->update();
		g->handleEvents();
	}
	g->cleanUp();
	return 0;
}