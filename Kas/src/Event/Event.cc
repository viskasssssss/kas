#include "Kas/Event/Event.hh"

namespace kas {
    // Event
    bool Event::is_in_category(EventCategory category) {
        return get_category_flags() & category;
    }

    // EventDispatcher
    EventDispatcher::EventDispatcher(Event& event)
			: m_event(event) {}

	template<typename T>
	bool EventDispatcher::dispatch(EventFn<T> func)
	{
		if (m_event.get_event_type() == T::get_static_type())
		{
			m_event.m_handled = func(*(T*)&m_event);
			return true;
		}
		return false;
	}
}