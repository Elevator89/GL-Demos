#ifndef INPUT_MOUSEMOVEEVENTARGS_H
#define INPUT_MOUSEMOVEEVENTARGS_H

#include "Common.Math/Algebra/Vec2.h"
#include "Common.Input/Mouse.h"
#include "Common.Input/Keyboard.h"
#include "Common.Input/EventArgs/MouseEventArgs.h"

namespace input {

	class MouseMoveEventArgs : public MouseEventArgs
	{
	public:
		MouseMoveEventArgs( const Mouse& mouse, const Keyboard& keyboard, math::Vec2 vector );
		MouseMoveEventArgs( const MouseMoveEventArgs& other );
		virtual ~MouseMoveEventArgs();

		MouseMoveEventArgs& operator=( const MouseMoveEventArgs& other );

		inline math::Vec2 GetVector() const { return m_vector; }

	private:
		math::Vec2 m_vector;
	};
}

#endif
