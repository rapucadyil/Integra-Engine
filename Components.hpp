#pragma once
#include <iostream>
#include "Math.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include "defines.h"
using namespace std;
namespace integra {
	namespace components {
		struct HealthComponent {
		private:
			float currentHealth;
			float maxHealth;
		public:
			inline HealthComponent(float c, float m) {
				this->currentHealth = c;
				this->maxHealth = m;
			}
			
			inline float getCurrentHealth() {
				return this->currentHealth;
			}

			inline float getMaxHealth() {
				return this->maxHealth;
			}
			/*
			Modifies the value of the current health
			*/
			inline void modifyCurrentHealth(float val) {
				this->currentHealth += val;

				// bounding logic
				if (this->currentHealth < 0)
					this->currentHealth = 0;
				if (this->currentHealth > this->maxHealth)
					this->currentHealth = this->maxHealth;

				//Debug stuff
				cout << this->currentHealth << endl;
			}
			/*
			Modifies the value of the maximum health (will be used for buffs etc...)
			*/
			inline void modifyMaxHealth(float val) {
				this->maxHealth += val;
				if (this->maxHealth < 0)
					this->maxHealth = 0;

				//Debug
				cout << this->maxHealth << std::endl;
			}
		};
		/*
		Defines a structure to hold transform properties (i.e. position)
		*/
		struct TransformComponent {
		private:
			math::Vector2D* m_Position;

		public:
			inline TransformComponent() {
				this->m_Position = new math::Vector2D(0, 0);
			}

			inline TransformComponent(math::Vector2D* instancePosition) {
				this->m_Position = instancePosition;
			}

			inline math::Vector2D* getPosition() {
				return this->m_Position;
			}
		};
		/*
		Defines a structure that handles the sprite and animation functionality
		*/
		struct SpriteComponent {
		private:
			const char* m_Filepath;
			SDL_Texture* m_Sprite;

		public:
			inline SpriteComponent(const char* flp) {
				this->m_Filepath = flp;

			}


			inline const char* getFilepath() {
				return this->m_Filepath;
			}
			
			inline void render(SDL_Rect* src, SDL_Rect* dest, SDL_Renderer* renderer) {
				SDL_Surface* tmp = IMG_Load(this->m_Filepath);
				this->m_Sprite = SDL_CreateTextureFromSurface(renderer, tmp);
				SDL_RenderCopy(renderer, this->m_Sprite, src, dest);
				SDL_FreeSurface(tmp);
				SDL_DestroyTexture(this->m_Sprite);
			}
		};

	}
}