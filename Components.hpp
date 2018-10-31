#pragma once
#include <iostream>
#include "Math.hpp"
#define printout std::cout

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
				printout << this->currentHealth << endl;
			}
			/*
			Modifies the value of the maximum health (will be used for buffs etc...)
			*/
			inline void modifyMaxHealth(float val) {
				this->maxHealth += val;
				if (this->maxHealth < 0)
					this->maxHealth = 0;

				//Debug
				printout << this->maxHealth << std::endl;
			}
		};
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

	}
}