#include "Game.h"
#include <iostream>
using namespace std;
namespace integra {
	namespace main {
		static bool m_bIsRunning;
		SDL_Rect* tmpDstRect = new SDL_Rect(); 
		Game::Game() {
			m_bIsRunning = true;
			this->cnt = 0;
		}
		bool Game::init(const char* title, int x, int y, int w, int h) {
			if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
				cout << "Failed to init SDL!" << SDL_GetError() << std::endl;
				return false;
			}
			else {
				this->m_Window = SDL_CreateWindow(title, x, y, w, h, SDL_WINDOW_SHOWN);
				if (!m_Window) {
					cout << "Failed to init Window!" << SDL_GetError() << std::endl;
					return false;
				}
				else {
					this->m_Renderer = SDL_CreateRenderer(this->m_Window, -1, 0);
				}
			}
			cout << "SDL Init, window and render successful" << std::endl;
			m_Player = new Character("Player", "assets/background.png");
			m_Input = new InputHandler(true);
			return true;
		}

		void Game::render() {
			SDL_SetRenderDrawColor(this->m_Renderer, 162, 216, 206, 0);
			SDL_RenderClear(this->m_Renderer);
			/*put the render code here*/
			m_Player->getSprite()->render(NULL, this->m_Input->getPossesRect(), this->m_Renderer);
			SDL_RenderPresent(this->m_Renderer);
		}

		void Game::handleEvents() {
			m_Input->getUserInput();
		}

		void Game::update() {
			/*std::cout << this->cnt << std::endl;
			this->cnt++;*/
		}

		void Game::cleanUp() {
			SDL_DestroyWindow(this->m_Window);
			SDL_DestroyRenderer(this->m_Renderer);
			cout << "Quit Successfully" << endl;;
			SDL_Quit();
		}

		static bool IsRunning() {
			return m_bIsRunning;
		}

	}
}