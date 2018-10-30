#pragma once
namespace integra {
	namespace math {

		struct Vector2D {
		private:
			float m_X;
			float m_Y;
		public:
			inline Vector2D(float x, float y) {
				this->m_X = x;
				this->m_Y = y;
			}

			inline float getX() {
				return this->m_X;
			}

			inline float getY() {
				return this->m_Y;
			}
		};

	}

}