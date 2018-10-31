#pragma once
namespace integra {
	namespace math {
		/*
		2 Dimensional Vector structure. Used to represent anything that has 2 dimensions such as Position,
		Velocity etc...
		*/
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

			inline Vector2D* distanceBetween(Vector2D* end) {
				Vector2D* distance;
				distance = new Vector2D(this->m_X - end->m_X, this->m_Y - end->m_Y);
				return distance;
			}

			inline void move(Vector2D* velocity) {
				this->m_X += velocity->m_X;
				this->m_Y += velocity->m_Y;
			}

			inline void moveRelative(Vector2D endPoint) {
				this->m_X += endPoint.m_X;
				this->m_Y += endPoint.m_Y;
			}

			inline void moveTowards(Vector2D* destinationPoint) {

				while (this->distanceBetween(destinationPoint) > 0) {
					this->move(new Vector2D(1, 1));
				}
			}
		};

	}

}