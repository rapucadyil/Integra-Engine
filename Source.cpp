/*
Includes
*/
#include "Game.h"
#include <iostream>
#include "Character.hpp"
#include "defines.h"
#include "Map.h"
#include "State.h"

/*
Namespaces
*/
using namespace std;
using namespace integra;
using namespace main;
using namespace statemachine;

bool m_bGameRunning = true;

int main(int argc, char* argv[]) {
	Game* g = new Game();
	Map* m = new Map();

	/* State test implementation
	State* testState = new State(0,nullptr, true);
	State* nextTestState = new State(1, nullptr, false);
	testState->setNextState(nextTestState);
	*/
	g->init("Integra Engine", center, center, /*Width->*/g->SCREEN_WIDTH, /*Height->*/g->SCREEN_HEIGHT);
	//std::cout << c->getHP()->getCurrentHealth() << end
	cout << m->getMapElementAtIndex(1, 0) << endl;
	/* Also test state implementation
	cout << "Next state valid test :" << testState->isNextStateValid() << endl;*/
	while (m_bGameRunning) {
		m_bGameRunning = g->getInputHandler()->getRunningState();
		g->render();	
		g->update();
		g->handleEvents();
	}
	g->cleanUp();
	return 0;
}