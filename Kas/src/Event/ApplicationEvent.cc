#include "Kas/Event/ApplicationEvent.hh"

#include <sstream>

namespace kas {
    // WindowResizeEvent
    std::string WindowResizeEvent::to_string() const
    {
    	std::stringstream ss;
    	ss << "WindowResizeEvent: " << m_width << ", " << m_height;
    	return ss.str();
    }
}
