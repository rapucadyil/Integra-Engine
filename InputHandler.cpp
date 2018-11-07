#include "InputHandler.h"
#include "SDL.h"
#include "Components.hpp"
#include "Math.hpp"
#include <iostream>
using namespace std;
using namespace components;
using namespace math;
namespace integra {
	namespace managers {
		InputHandler::InputHandler(bool active)
		{
			this->m_bIsActive = active;
			this->m_refbIsRunning = true;
			this->m_PossesDstRect = new SDL_Rect();
			this->m_PossesDstRect->x = 0;
			this->m_PossesDstRect->y = 0;
			this->m_PossesDstRect->w = 100;
			this->m_PossesDstRect->h = 100;
			this->m_MoveSpeed = 15;
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
						this->m_PossesDstRect->x -= this->m_MoveSpeed;
						this->getCurrentlyPossessed()->getPosition()->getPosition()->move(new Vector2D(-1, 0));
						break;
					case SDLK_RIGHT:
						cout << "right pressed" << endl;
						this->m_PossesDstRect->x += this->m_MoveSpeed;
						this->getCurrentlyPossessed()->getPosition()->getPosition()->move(new Vector2D(1, 0));
						break;
					case SDLK_ESCAPE:
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