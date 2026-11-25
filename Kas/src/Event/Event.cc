#include "kpch.hh"

#include "Kas/Event/Event.hh"

namespace kas {
    // Event
    bool Event::is_in_category(EventCategory category) {
        return get_category_flags() & category;
    }

    // EventDispatcher
    EventDispatcher::EventDispatcher(Event& event)
			: m_event(event) {}
}
