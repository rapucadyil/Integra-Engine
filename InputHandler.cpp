#include "InputHandler.h"
#include "SDL.h"
#include "Components.hpp"
#include "Game.h"
#include "Math.hpp"
#include <iostream>
using namespace std;
using namespace components;
using namespace math;
using namespace main;
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
						/* Basic screen bounds collision implementation*/
						if (this->isNextSpaceValid("-X"))
							this->m_PossesDstRect->x -= this->m_MoveSpeed;
						break;
					case SDLK_a:
						cout << "alt_left pressed" << endl;
						/* Basic screen bounds collision implementation*/
						if (this->isNextSpaceValid("-X"))
							this->m_PossesDstRect->x -= this->m_MoveSpeed;

						break;
					case SDLK_d:
						cout << "alt_right pressed" << endl;
						/* Basic screen bounds collision implementation*/
						if (this->isNextSpaceValid("+X"))
							this->m_PossesDstRect->x += this->m_MoveSpeed;
						break;
					case SDLK_RIGHT:
						cout << "right pressed" << endl;
						/* Basic screen bounds collision implementation*/
						if (this->isNextSpaceValid("+X"))
							this->m_PossesDstRect->x += this->m_MoveSpeed;
						break;
					case SDLK_UP:
						cout << "up pressed" << endl;
						if (this->m_PossesDstRect->y > 0)
							this->m_PossesDstRect->y -= this->m_MoveSpeed;
						break;
					case SDLK_w:
						cout << "alt_up pressed" << endl;
						this->m_PossesDstRect->y -= this->m_MoveSpeed;
						break;
					case SDLK_s:
						cout << "alt_down pressed" << endl;
						this->m_PossesDstRect->y += this->m_MoveSpeed;
						break;
					case SDLK_DOWN:
						cout << "down pressed" << endl;
						this->m_PossesDstRect->y += this->m_MoveSpeed;
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
					case SDLK_w:
						cout << "alt_up released" << endl;
						break;
					case SDLK_s:
						cout << "alt_down released" << endl;
						break;
					case SDLK_a:
						cout << "alt_left released" << endl;
						break;
					case SDLK_d:
						cout << "alt_right released" << endl;
						break;
					}
					break;
				case SDL_QUIT:
					this->m_refbIsRunning = false;
					break;

				}
			}
		}
		/*
		Checks if the next space is valid (for the moment with regards to screen bounds)
		*/
		bool InputHandler::isNextSpaceValid(const char* dir) {
			if (dir == "-X") {
				if (this->m_PossesDstRect->x > 0)
					return true;
				else
					return false;
			}
			if (dir == "+X") {
				if (this->m_PossesDstRect->x < Game::SCREEN_WIDTH - this->m_PossesDstRect->w)
					return true;
				else
					return false;
			}

			if (dir == "-Y") {
				if (this->m_PossesDstRect->y > 0)
					return true;
				else
					return false;
			}
			if (dir == "+Y") {
				if (this->m_PossesDstRect->y < Game::SCREEN_HEIGHT - this->m_PossesDstRect->h)
					return true;
				else
					return false;
			}
		}

		bool InputHandler::isCollidingWithGameObject(SDL_Rect* colliding, const char* dir) {
			// Do collision handling with another character/object in game world here
			
			if (dir == "right") {
				if ((this->m_PossesDstRect->x +  this->m_PossesDstRect->w)< colliding->x)
					return true;
				return false;
			}
			if (dir == "left") {
				if (this->m_PossesDstRect->x > (colliding->x + colliding->w))
					return true;
				return false;
			}
			if (dir == "up") {

			}
			if (dir == "down") {

			}
		}
	}
}