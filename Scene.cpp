#include "Scene.hpp"

Scene::Scene(const char* name, Scene* next) {
	this->m_Name = name;
	this->m_Next = next;
}

Scene::~Scene() {
	this->m_Name, this->m_Next = nullptr;
}


