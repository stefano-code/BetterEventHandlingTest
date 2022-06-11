#ifndef DATA_DOUBLE_EVENTS_
#define DATA_DOUBLE_EVENTS_

#include "Event.h"

namespace Technogym
{
	namespace EventHandling
	{
	
		class DataDoubleEvent : public EventHandling::Event
		{
		public :
			DataDoubleEvent( Tag t,double v) ;
			double GetValue() const ;
			virtual EventHandling::Event* Clone() const ;
			virtual std::string SerializeOut() const;
		private :
			double val ;
		} ;
	}
}
#endif
