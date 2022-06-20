// Event.h

#ifndef EVENT_

#define EVENT_

#pragma warning (disable:4786)
#pragma warning( disable: 4018 )

#include "Tag.h"
#include <string>

namespace EventHandling
{
	class Event
	{
	public :
		Event( Tag t ) ;
		virtual ~Event() ;
		Tag GetTag() const ;
		virtual Event* Clone() const = 0 ;
		virtual std::string SerializeOut() const = 0;
	private :
		Tag tag ;
	} ;
}

#endif
