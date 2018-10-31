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
			SDL_Texture* m_Sprite;
			SDL_Surface* m_SpriteSurface;
			SDL_Renderer* m_Renderer;
			int m_MaxFrames;
			int m_CurrentFrame;
			int m_FrameWidth;
			int m_FrameHeight;

		public:
			inline SpriteComponent() {

			}

			inline SDL_Texture* getSprite() {
				return this->m_Sprite;
			}
			inline SDL_Surface* getSpriteSurface() {
				return this->m_SpriteSurface;
			}
			inline SDL_Renderer* getRenderer() {
				return this->m_Renderer;
			}
			inline int getMaxFrames() {
				return this->m_MaxFrames;
			}
			inline int getCurrentFrame() { 
				return this->m_CurrentFrame;
			}
			inline int getFrameWidth() {
				return this->m_FrameWidth;
			}
			inline int getFrameHeight() {
				return this->m_FrameHeight;
			}

			//TODO(rj): figure out and implement rendering (first without anim)
			//TODO(rj): figure out and implement rendering (with anim logic)
		};

	}
}