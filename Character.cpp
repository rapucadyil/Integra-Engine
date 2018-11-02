#include "Character.hpp"
#include "Game.h"
using namespace integra;
using namespace main;
namespace integra {

	Character::Character(const char* id, const char* sprFilePath)
	{
		this->m_Id = id;
		this->m_Hp = new HealthComponent(300, 300);
		this->m_Position = new TransformComponent();
		this->m_ImagePath = sprFilePath;
		this->m_SpriteComp = new SpriteComponent(this->m_ImagePath);
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

	

	void Character::render(SDL_Renderer* renderer)
	{
		/* Do render for this specific character here */
		this->m_Sprite = IMG_Load(this->m_ImagePath);
		SDL_Texture* spriteText = SDL_CreateTextureFromSurface(renderer, this->m_Sprite);
		this->m_SpriteComp->render(NULL, NULL, renderer);
	}

	void Character::move(math::Vector2D * destination)
	{
		//TODO(rj): find a way to test the below code
		this->m_Position->getPosition()->moveTowards(destination);	
	}

	void Character::spriteSystemInitialization() {

	}

}