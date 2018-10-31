#include "Character.hpp"


namespace integra {

	Character::Character(const char* id)
	{
		this->m_Id = id;
		this->m_Hp = new HealthComponent(300, 300);
		this->m_Position = new TransformComponent();
		//this->m_Sprite = new SpriteComponent();
		//INIT_SPRITE_SYSTEM();	//TODO(rj): implement this function/macro properly with correct params and logic
	}

	Character::~Character()
	{ 
		this->m_Id, this->m_Hp, this->m_Position = nullptr;
	}

	void Character::update()
	{


		//Testing
		//this->m_Hp->modifyCurrentHealth(-10);
	}

	

	void Character::render()
	{
		/* Do render for this specific character here */
		//this->m_Sprite = new SpriteComponent()
	}

	void Character::move(math::Vector2D * destination)
	{
		//TODO(rj): find a way to test the below code
		this->m_Position->getPosition()->moveTowards(destination);	
	}

	void Character::spriteSystemInitialization() {

	}

}