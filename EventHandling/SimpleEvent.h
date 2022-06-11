// SimpleEvent.h

#ifndef SIMPLEEVENT_

#define SIMPLEEVENT_

#include "Event.h"


namespace Technogym
{
	namespace EventHandling
	{
		class SimpleEvent : public Event
		{
		public :
			SimpleEvent( Tag t ) ;
			virtual Event* Clone() const ;
			virtual std::string SerializeOut() const;
		} ;
	}
}

#endif
