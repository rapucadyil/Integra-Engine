#pragma once
namespace integra {
	namespace statemachine {
		class State {
		private:
			int m_Id;
			State* m_NextState;
			bool m_Completed;
			const char* m_UniqID;

		public:
			State(int id, State* next, bool completed);
			~State();

			bool isNextStateValid();
			void monitorCompletion();

			inline const char* getUniqID() {
				return this->m_UniqID;
			}

			inline State* getNextState() {
				return this->m_NextState;
			}

			inline int getID() {
				return this->m_Id;
			}

			inline void setNextState(State* next) {
				this->m_NextState = next;
			}
			inline void setID(int id) {
				this->m_Id = id;
			}
			inline void setCompleted(bool completed) {
				this->m_Completed = completed;
			}
		};
	}
}