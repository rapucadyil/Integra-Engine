#include "State.h"
namespace integra {
	namespace statemachine {

		State::State(int id, State* next, bool completed) {
			this->m_Id = id;
			this->m_NextState = next;
			this->m_Completed = completed;
		}

		State::~State() {
			this->m_Completed = false;
			this->m_Id = -1;
			this->m_NextState = nullptr;
		}

		bool State::isNextStateValid() {
			if (this->m_Completed) {

				if (this->m_NextState == nullptr) {
					return false;
				}
				else {
					if (this->m_NextState->m_Id <= this->m_Id)
						return false;
					else {
						return true;
					}
				}
			}
			else {
				return false;
			}
		}
	}
}