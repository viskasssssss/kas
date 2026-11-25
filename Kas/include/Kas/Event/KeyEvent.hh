#pragma once

#include "Kas/Event/Event.hh"

namespace kas {

	class KAS_API KeyEvent : public Event
	{
	public:
		inline int get_key_code() const { return m_key_code; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode);

		int m_key_code;
	};

	class KAS_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeat_count);

		inline int GetRepeatCount() const { return m_repeat_count; }

		std::string to_string() const override;

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_repeat_count;
	};

	class KAS_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode);

		std::string to_string() const override;

		EVENT_CLASS_TYPE(KeyReleased)
	};
}