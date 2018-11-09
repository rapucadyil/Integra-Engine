#pragma once
#include "Character.hpp"
#include <SDL.h>

namespace integra {
	namespace managers {
		class InputHandler {
		private:
			bool m_bIsActive;
			bool m_refbIsRunning;
			Character* m_CurrentPossess;
			SDL_Rect* m_PossesDstRect;

			int m_MoveSpeed;
		public:
			InputHandler(bool active);
			~InputHandler();

			bool isNextSpaceValid(const char* );
			bool isCollidingWithGameObject(SDL_Rect* , const char*);

			void getUserInput();

			inline Character* getCurrentlyPossessed() {
				return this->m_CurrentPossess;
			}

			inline SDL_Rect* getPossesRect() {
				return this->m_PossesDstRect;
			}

			inline void setCurrentlyPossessed(Character* c) {
				this->m_CurrentPossess = c;
			}

			inline bool getRunningState() {
				return this->m_refbIsRunning;
			}

		};
	}
}