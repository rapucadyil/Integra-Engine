#pragma once
#include <vector>
#include <iostream>
#include "Scene.hpp"
using namespace std;
namespace integra {
	namespace managers {
		class SceneManager {
		private:
			Scene* m_CurrentScene;
			vector<Scene> m_Scenes;

		public:
			SceneManager();
			~SceneManager();

			void update();
		};
	}
}