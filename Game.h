#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "defines.h"

using namespace std;
namespace integra {
	namespace main {
		
		class Game {
		private:
			bool m_bIsRunning;
			int cnt;
			Character* m_Player;
			SDL_Window* m_Window;            
			SDL_Renderer* m_Renderer;
		public:
			static const int SCREEN_WIDTH = 640;
			static const int SCREEN_HEIGHT = 480;
			Game();
			bool init(const char* title, int x, int y, int w, int h);
			~Game();
			void update();
			void render();
			void handleEvents();
			void cleanUp();

			inline bool isRunning() {
				return this->m_bIsRunning;
			}
		};
} }