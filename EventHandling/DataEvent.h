#ifndef DATA_EVENTS_
#define DATA_EVENTS_

#include "Event.h"

namespace Technogym
{
	namespace EventHandling
	{
		typedef int Value ;
	
		class DataEvent : public EventHandling::Event
		{
		public :
			DataEvent( Tag t,Value v) ;
			Value GetValue() const ;
			virtual EventHandling::Event* Clone() const ;
		private :
			Value v ;
		} ;
	}
}
#endif
