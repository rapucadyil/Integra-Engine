#pragma once
#include "State.h"
namespace integra {
	namespace statemachine {
		class MainMenuState : public State {
		private:

		public:
			MainMenuState();
			~MainMenuState();
			void execute();
		};
	}
}