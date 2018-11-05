#pragma once
class Scene {
private:
	bool m_bIsCompleted;

public:
	Scene();
	~Scene();

	inline bool IsCompleted() {
		return this->m_bIsCompleted;
	}
};