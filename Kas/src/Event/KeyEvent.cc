#include "kpch.hh"

#include "Kas/Event/KeyEvent.hh"

#include <sstream>

namespace kas {
    // KeyEvent
    KeyEvent::KeyEvent(int keycode)
			: m_key_code(keycode) {}
    
    // KeyPressedEvent
    KeyPressedEvent::KeyPressedEvent(int keycode, int repeat_count)
			: KeyEvent(keycode), m_repeat_count(repeat_count) {}

    std::string KeyPressedEvent::to_string() const
	{
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_key_code << " (" << m_repeat_count << " repeats)";
		return ss.str();
	}

    // KeyReleasedEvent
    KeyReleasedEvent::KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

	std::string KeyReleasedEvent::to_string() const
	{
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_key_code;
		return ss.str();
	}
}
