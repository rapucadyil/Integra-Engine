#include "InputHandler.h"
#include "SDL.h"
#include <iostream>
using namespace std;
namespace integra {
	namespace managers {
		InputHandler::InputHandler(bool active)
		{
			this->m_bIsActive = active;
			this->m_refbIsRunning = true;
		}
		void InputHandler::getUserInput() {
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type)
				{
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
					case SDLK_LEFT:
						cout << "left pressed" << endl;
						break;
					case SDLK_RIGHT:
						cout << "right pressed" << endl;
						break;
					case SDLK_ESCAPE:
						cout << "Quit success!!" << endl;
						this->m_refbIsRunning = false;
						break;
					}
				break;
				case SDL_KEYUP:
					switch (event.key.keysym.sym) {
					case SDLK_LEFT:
						cout << "left released" << endl;
						break;
					case SDLK_RIGHT:
						cout << "right released" << endl;
						break;
					}
				break;
				case SDL_QUIT:
					this->m_refbIsRunning = false;
				break;
					
				}
			}
		}
	}
}