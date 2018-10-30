#pragma once
#include <iostream>
#define printout std::cout
#define end std::endl

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
				printout << this->currentHealth << end;
			}
			/*
			Modifies the value of the maximum health (will be used for buffs etc...)
			*/
			inline void modifyMaxHealth(float val) {
				this->maxHealth += val;
				if (this->maxHealth < 0)
					this->maxHealth = 0;

				//Debug
				printout << this->maxHealth << end;
			}
		};
		struct TransformComponent {

		};
	}
}

