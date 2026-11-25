#include "kpch.hh"

#include "Kas/Event/MouseEvent.hh"

#include <sstream>

namespace kas {
    // MouseMovedEvent
    MouseMovedEvent::MouseMovedEvent(float x, float y)
		: m_mouse_x(x), m_mouse_y(y) {}

    std::string MouseMovedEvent::to_string() const
	{
		std::stringstream ss;
		ss << "MouseMovedEvent: " << m_mouse_x << ", " << m_mouse_y;
		return ss.str();
	}

    // MouseScrolledEvent
    MouseScrolledEvent::MouseScrolledEvent(float x_offset, float y_offset)
		: m_x_offset(x_offset), m_y_offset(y_offset) {}

    std::string MouseScrolledEvent::to_string() const
	{
		std::stringstream ss;
		ss << "MouseScrolledEvent: " << get_x_offset() << ", " << get_y_offset();
		return ss.str();
	}

    // MouseButtonEvent
    MouseButtonEvent::MouseButtonEvent(int button)
		: m_button(button) {}

    // MouseButtonPressedEvent
    MouseButtonPressedEvent::MouseButtonPressedEvent(int button)
		: MouseButtonEvent(button) {}

	std::string MouseButtonPressedEvent::to_string() const
	{
		std::stringstream ss;
		ss << "MouseButtonPressedEvent: " << m_button;
		return ss.str();
	}

    // MouseButtonReleasedEvent
    MouseButtonReleasedEvent::MouseButtonReleasedEvent(int button)
		: MouseButtonEvent(button) {}

	std::string MouseButtonReleasedEvent::to_string() const
	{
		std::stringstream ss;
		ss << "MouseButtonReleasedEvent: " << m_button;
		return ss.str();
	}
}
