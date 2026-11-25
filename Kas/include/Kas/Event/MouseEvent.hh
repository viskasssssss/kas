#pragma once

#include "Kas/Event/Event.hh"

#include <string>

namespace kas {

	class KAS_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y);

		inline float get_x() const { return m_mouse_x; }
		inline float get_y() const { return m_mouse_y; }

		std::string to_string() const override;

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_mouse_x, m_mouse_y;
	};

	class KAS_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float x_offset, float y_offset);

		inline float get_x_offset() const { return m_x_offset; }
		inline float get_y_offset() const { return m_y_offset; }

		std::string to_string() const override;

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float m_x_offset, m_y_offset;
	};

	class KAS_API MouseButtonEvent : public Event
	{
	public:
		inline int get_mouse_button() const { return m_button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button);

		int m_button;
	};

	class KAS_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button);

		std::string to_string() const override;

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class KAS_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button);

		std::string to_string() const override;

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}