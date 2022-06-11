// EventSource.cpp

#include <stddef.h>
#include "..\Reusable\CE_Assert.h" 
#include "Event.h"
#include "EventSource.h"
#include "EventSink.h"


using namespace std ;
using namespace Technogym::EventHandling ;

void EventSource :: Subscribe( Tag t, EventSink* s )
{
	pair< const Tag, EventSink* > p( t, s ) ;
	dispMap.insert( p ) ;
}
void EventSource :: Dispatch( const Event& e )
{
  Tag t = e.GetTag() ;
  DispatchMap::iterator i = dispMap.find( t ) ;
  while( i != dispMap.end() && (*i).first == t )
  {
	  (*i).second->Notify( e ) ;
	  ++i ;
  }
}
void EventSource :: UnSubscribe( EventSink* s )
{
	DispatchMap::iterator i = dispMap.begin() ;
	while( i != dispMap.end() )
	{
		if( (*i).second == s )
			{
		    dispMap.erase( i ) ;
			i = dispMap.begin() ;
			}
		else
			++i ;
	}
}
void EventSource::UnsubscribeSingleEvent(EventSink* s,Tag t)
{
	DispatchMap::iterator i = dispMap.find(t) ;
	if( i != dispMap.end() )
		dispMap.erase(i) ;
}
