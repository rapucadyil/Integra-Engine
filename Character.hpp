#pragma once
#include "Components.hpp"
#include <SDL.h>

#define printout std::cout
#define end std::endl

using namespace integra;
using namespace components;
namespace integra {
	class Character {
	public:
		Character(const char* id);
		~Character();

		void update();
		void render();

		inline HealthComponent* getHP() {
			return this->m_Hp;
		}
		
		inline const char* getID() {
			return this->m_Id;
		}

		inline TransformComponent* getPosition() {
			return this->m_Position;
		}
	private:
		const char* m_Id;
		HealthComponent* m_Hp;
		TransformComponent* m_Position;
		SDL_Texture* m_Sprite;
	};

}