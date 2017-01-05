#ifndef INPUT_KEYEVENTARGS_H
#define INPUT_KEYEVENTARGS_H

#include "Common.Input/Keyboard.h"

namespace input {

	class KeyEventArgs
	{
	public:
		KeyEventArgs( const Keyboard& keyboard, int key );
		KeyEventArgs( const KeyEventArgs& other );
		virtual ~KeyEventArgs();

		KeyEventArgs& operator=( const KeyEventArgs& other );

	public:
		inline Keyboard GetKeyboardState() const { return m_keyboard; }
		inline int GetKey() const { return m_key; }

	private:
		Keyboard m_keyboard;
		int m_key;
	};
}

#endif
