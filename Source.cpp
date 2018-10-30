/*
Includes
*/
#include "Game.h"
#include <iostream>
#include "Character.hpp"
/*
Defines
*/
#define center SDL_WINDOWPOS_CENTERED
#define printout std::cout
#define end std::endl
/*
Namespaces
*/
using namespace std;
using namespace integra;
using namespace main;

int main(int argc, char* argv[]) {
	Game* g = new Game();
	g->init("Integra Engine", center, center, /*Width->*/g->SCREEN_WIDTH, /*Height->*/g->SCREEN_HEIGHT);
	Character* c = new Character("Player");
	printout << c->getID() << end;
	//std::cout << c->getHP()->getCurrentHealth() << end
	while (g->isRunning()) {
		g->update();
		g->handleEvents();
		g->render();
		c->update();
	}
	g->cleanUp();
	return 0;
}