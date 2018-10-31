#pragma once
#include "Components.hpp"
#include "Math.hpp"
#include "defines.h"
using namespace integra;
using namespace components;
namespace integra {
	class Character {
	public:
		Character(const char* id);
		~Character();

		void update();
		void render();
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
	private:
		const char* m_Id;
		HealthComponent* m_Hp;
		TransformComponent* m_Position;
		SpriteComponent* m_Sprite;
	public:
		void spriteSystemInitialization();
	};

}