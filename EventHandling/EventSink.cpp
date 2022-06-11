// EventSink.cpp

#include <stddef.h>
#include "..\Reusable\CE_Assert.h" 
#include "EventSink.h"
#include "..\Reusable\CriticalSectionLock.h"
#include "Invoker.h"


using namespace std ;
using namespace Technogym::EventHandling ;
using namespace Technogym::Reusable ;


EventSink :: ~EventSink()
{
	CleanupQueue() ;
	CleanupDispMap() ;
}
void EventSink :: Notify( const Event& e )
{
	CriticalSectionLock l( guard ) ;
	queue.push( e.Clone() ) ;
}
auto_ptr< Event > EventSink :: GetEvent()
{
	CriticalSectionLock l( guard ) ;

	if( queue.empty() )
		return(auto_ptr< Event >(NULL) ) ;
	else
	{
		Event* e = queue.front() ;  //## Documentations says top()
		queue.pop() ;
		return(auto_ptr< Event >(e) ) ;
	}
}
void EventSink :: CleanupQueue()
{
	while( ! queue.empty() )
	{
		Event* e = queue.front() ;
		delete e ;
		queue.pop() ;
	}
}
void EventSink :: HandleEvent( const Event* e )
{
  DispMap::iterator i = dispMap.find( e->GetTag() ) ;
  if( i != dispMap.end() )
    (*i).second->InvokeHandler( e ) ;
}
void EventSink :: HandleFirstEvent()
{
	auto_ptr< Event > e( GetEvent() ) ;
	const Event* tmpPtr = e.get() ;
	if( tmpPtr != NULL )
    HandleEvent( tmpPtr ) ;
}
void EventSink :: CleanupDispMap()
{
  // Each Invoker* in the map has been allocated with new
  // in SubscribeEvent, and must be deleted before destroying the map
	DispMap::iterator i = dispMap.begin() ;
	while( i != dispMap.end() )
	{
		delete (*i).second ;
		++i ;
	}

}

bool EventSink::RemoveDispMapElement(Tag t)
{
	DispMap::iterator i = dispMap.find(t);
	if(i != dispMap.end())
	{
		delete (*i).second;
		dispMap.erase(i);
		return true;
	}
	return false;
}

void EventSink::UnsubscribeEvent(EventSource& s,Tag t)
{
	if(RemoveDispMapElement(t)==true)
		s.UnsubscribeSingleEvent(this,t);
}
