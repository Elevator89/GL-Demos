#ifndef INPUT_KEYBOARD_H
#define INPUT_KEYBOARD_H

#include "Common.Input/ButtonState.h"
#include "Common.Input/KeyboardModifier.h"

namespace input {

	class Keyboard
	{
	public:
		Keyboard();
		Keyboard( const Keyboard& keyboard );
		~Keyboard();

		Keyboard& operator=( const Keyboard& other );

		inline ButtonState GetModifierState( KeyboardModifier modifier ) const { return m_keys[int ( modifier )]; }
		inline void SetModifierState( KeyboardModifier modifier, ButtonState state ) { m_keys[int ( modifier )] = state; }

	private:
		ButtonState m_keys[4];
	};
}

#endif
