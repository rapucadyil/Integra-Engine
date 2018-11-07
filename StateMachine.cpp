#include <iostream>
#include "StateMachine.h"

namespace integra {
	namespace statemachine {
		StateMachine::StateMachine() {

		}

		StateMachine::~StateMachine() {
			this->m_CurrentState = nullptr;
			this->m_ValidState.clear();
		}

		bool StateMachine::setCurrentState(State* n) {
			vector<const char*> uniqIds = vector<const char*>();
			for (int i = 0; i < this->m_ValidState.size(); i++) {
				uniqIds.insert(uniqIds.begin(), this->m_ValidState[i]->getUniqID());
			}
			for (const char* id : uniqIds) {
				if (id == n->getUniqID()) {
					return false;
				}
			}
			this->m_CurrentState = n;
			return true;
		}

		void StateMachine::updateStates() {
			while (this->m_CurrentState->isNextStateValid()) {
				setCurrentState(this->m_CurrentState->getNextState());
			}
			// Debug
			std::cout << "There is no next valid state" << std::endl;
		}
	}
}