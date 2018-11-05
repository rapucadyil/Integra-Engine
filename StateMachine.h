#pragma once
#include "State.h"
#include <vector>
using namespace std;
namespace integra {
	namespace statemachine {

		class StateMachine {
		private:
			State* m_CurrentState;
			vector<State*> m_ValidState;
		public:
			StateMachine();
			~StateMachine();

			inline State* getCurrentState() {
				return this->m_CurrentState;
			}

			void setCurrentState(State* n);
		};
	}
}