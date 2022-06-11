#ifndef MESSAGE_EVENTS_
#define MESSAGE_EVENTS_

#include "Event.h"

namespace Technogym
{
	namespace EventHandling
	{
		class MessageEvent : public EventHandling::Event
		{
		public :
			MessageEvent(Tag,TCHAR*) ;
			TCHAR* GetValue() const ;
			virtual EventHandling::Event* Clone() const ;
			virtual std::string SerializeOut() const ;
		private :
			//			Technogym::Properties::BaseProperty* bProp;
			TCHAR* msg;
		};
	}
}

#endif
