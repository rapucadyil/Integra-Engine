#include "Character.hpp"

#define printout std::cout
#define end std::endl

namespace integra {

	Character::Character(const char* id)
	{
		this->m_Id = id;
		this->m_Hp = new HealthComponent(300, 300);
	}

	Character::~Character()
	{ 
		this->m_Id, this->m_Hp, this->m_Position, this->m_Sprite = nullptr;

	}

	void Character::update()
	{


		//Testing
		this->m_Hp->modifyCurrentHealth(-10);
	}

	

	void Character::render()
	{
		/* Do render for this specific character here */
	}

}

