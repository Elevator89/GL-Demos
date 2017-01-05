#ifndef INPUT_MOUSE_H
#define INPUT_MOUSE_H

#include "Common.Math/Algebra/Vec2.h"
#include "Common.Input/ButtonState.h"
#include "Common.Input/MouseButton.h"

namespace input
{

	class Mouse
	{
	public:
		Mouse();
		Mouse( const Mouse& mouse );
		virtual ~Mouse();

		Mouse& operator=( const Mouse& other );

		inline math::Vec2 GetPosition() const { return m_position; }
		inline void SetPosition( const math::Vec2& position ) { m_position = position; }

		inline int GetWheelPosition() const { return m_wheelPosition; }
		inline void SetWheelPosition( int wheelPosition ) { m_wheelPosition = wheelPosition; }

		inline ButtonState GetButtonState( MouseButton button ) const { return m_buttons[int ( button )]; }
		inline void SetButtonState( MouseButton button, ButtonState state ) { m_buttons[int ( button )] = state; }

	private:
		ButtonState m_buttons[3];
		math::Vec2 m_position;
		int m_wheelPosition;
	};
}

#endif
