#pragma once
class Scene {
private:
	const char* m_Name;
	Scene* m_Next;
public:
	Scene(const char* name, Scene* next);
	~Scene();

	inline const char* getName() {
		return this->m_Name;
	}
	inline Scene* getNext() {
		return this->m_Next;
	}

};