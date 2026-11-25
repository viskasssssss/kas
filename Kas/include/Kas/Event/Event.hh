#pragma once

#include "Kas/Core/Defines.hh"

#include <string>
#include <functional>

namespace kas {
    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput       = BIT(1),
        EventCategoryKeyboard    = BIT(2),
        EventCategoryMouse       = BIT(3),
        EventCategoryMouseButton = BIT(4),
    };

#define EVENT_CLASS_TYPE(type) static EventType get_static_type() { return EventType::##type; }\
                                virtual EventType get_event_type() const override { return get_static_type(); }\
                                virtual const char* get_name() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int get_category_flags() const override { return category; }

    class KAS_API Event {
        friend class EventDispatcher;
    public:
        virtual EventType get_event_type() const = 0;
        virtual const char* get_name() const = 0;
        virtual int get_category_flags() const = 0;
        virtual std::string to_string() const { return get_name(); };

        bool is_in_category(EventCategory category);
    protected:
        bool m_handled = false;
    };

    class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event);

		template<typename T>
		bool dispatch(EventFn<T> func);
	private:
		Event& m_event;
	};

    inline std::string format_as(const Event& e) {
        return e.to_string();
    }
}
