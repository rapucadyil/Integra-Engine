#pragma once
#include "Components.hpp"
#include "Math.hpp"
#include "defines.h"
using namespace integra;
using namespace components;
namespace integra {
	class Character {
	public:
		Character(const char* id, const char* sprFilePath);
		~Character();

		void update();
		void render(SDL_Renderer* renderer);
		void move(math::Vector2D* destination);
		inline HealthComponent* getHP() {
			return this->m_Hp;
		}
		
		inline const char* getID() {
			return this->m_Id;
		}

		inline TransformComponent* getPosition() {
			return this->m_Position;
		}
		
		inline SpriteComponent* getSprite() {
			return this->m_SpriteComp;
		}
	private:
		const char* m_Id;
		const char* m_ImagePath;
		SDL_Surface* m_Sprite;
		HealthComponent* m_Hp;
		TransformComponent* m_Position;
		SpriteComponent* m_SpriteComp;
	public:
		void spriteSystemInitialization();
	};

}