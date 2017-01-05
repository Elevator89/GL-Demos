#ifndef INPUT_MOUSEEVENTARGS_H
#define INPUT_MOUSEEVENTARGS_H

#include "Common.Input/Keyboard.h"
#include "Common.Input/Mouse.h"

namespace input {

	class MouseEventArgs
	{
	public:
		virtual ~MouseEventArgs();

		inline const Keyboard GetKeyboardState() const { return m_keyboard; }
		inline const Mouse GetMouseState() const { return m_mouse; }

	protected:
		MouseEventArgs( const Mouse& mouse, const Keyboard& keyboard );
		MouseEventArgs( const MouseEventArgs& other );
		MouseEventArgs& operator=( const MouseEventArgs& other );

	private:
		Mouse m_mouse;
		Keyboard m_keyboard;
	};
}

#endif
