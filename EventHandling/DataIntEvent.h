#ifndef DATA_INT_EVENTS_
#define DATA_INT_EVENTS_

#include "Event.h"

namespace Technogym
{
	namespace EventHandling
	{
		typedef int Value ;
	
		class DataIntEvent : public EventHandling::Event
		{
		public :
			DataIntEvent( Tag t,Value v) ;
			Value GetValue() const ;
			virtual EventHandling::Event* Clone() const ;
			virtual std::string SerializeOut() const;
		private :
			Value val ;
		} ;
	}
}
#endif
