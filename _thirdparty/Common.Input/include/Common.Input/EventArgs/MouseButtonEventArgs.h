#ifndef INPUT_MOUSEBUTTONPRESSEVENTARGS_H
#define INPUT_MOUSEBUTTONPRESSEVENTARGS_H

#include "Common.Input/Mouse.h"
#include "Common.Input/Keyboard.h"
#include "Common.Input/EventArgs/MouseEventArgs.h"

namespace input {

	class MouseButtonEventArgs : public MouseEventArgs
	{
	public:
		MouseButtonEventArgs( const Mouse& mouse, const Keyboard& keyboard, MouseButton button );
		MouseButtonEventArgs( const MouseButtonEventArgs& other );
		virtual ~MouseButtonEventArgs();

		MouseButtonEventArgs& operator=( const MouseButtonEventArgs& other );

		inline MouseButton GetButton() const { return m_button; }

	private:
		MouseButton m_button;
	};
}
#endif
