// EventSource.h

#ifndef EVENTSOURCE_

#define EVENTSOURCE_

#pragma warning( disable: 4786 )

#include <map>


#include "Tag.h"

namespace Technogym
{
	namespace EventHandling
	{
    class EventSink ;
    class Event ;

		class EventSource
		{
		public :
			void Subscribe( Tag t, EventSink* s ) ;
			void UnSubscribe( EventSink* s ) ;
			void Dispatch( const Event& e ) ;
			void UnsubscribeSingleEvent(EventSink* s,Tag t);
		private :
			typedef std::multimap< Tag, EventSink* > DispatchMap ;
			DispatchMap dispMap ;
		} ;
	}
}

#endif
