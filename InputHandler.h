#pragma once
namespace integra {
	namespace managers {
		class InputHandler {
		private:
			bool m_bIsActive;
			bool m_refbIsRunning;
		public:
			InputHandler(bool active);
			~InputHandler();

			void getUserInput();

			inline bool getRunningState() {
				return this->m_refbIsRunning;
			}

		};
	}
}