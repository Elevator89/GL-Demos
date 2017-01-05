#ifndef INPUT_MOUSESCROLLEVENTARGS_H
#define INPUT_MOUSESCROLLEVENTARGS_H

#include "Common.Input/Mouse.h"
#include "Common.Input/Keyboard.h"
#include "Common.Input/EventArgs/MouseEventArgs.h"

namespace input {

	class MouseScrollEventArgs : public MouseEventArgs
	{
	public:
		MouseScrollEventArgs( const Mouse& mouse, const Keyboard& keyboard, int delta );
		MouseScrollEventArgs( const MouseScrollEventArgs& other );
		virtual ~MouseScrollEventArgs();

		MouseScrollEventArgs& operator=( const MouseScrollEventArgs& other );

		inline int GetDelta() const { return m_delta; }

	private:
		int m_delta;
	};
}

#endif
