// EventSink.h

#ifndef EVENTSINK_

#define EVENTSINK_

#pragma warning( disable: 4786 )

#include <memory>
#include "EventQueue.h" 
#include "Event.h" 
#include "EventSource.h" 
#include "..\Reusable\CriticalSection.h"
#include "..\Reusable\CheckedCast.h"
#include "Invoker.h"

namespace Technogym
{
	namespace EventHandling
	{
		class EventSink
		{
		public :
			virtual ~EventSink() ;
			virtual void Notify( const Event& e )  ;
			std::auto_ptr< Event > GetEvent() ; // Returns NULL if the queue is empty
			//## potrebbe avere anche una WaitForEvent con timeout
			void CleanupQueue() ;
		
		protected :
			template< class T1, class T2 > 
			void SubscribeEvent( EventSource& s, Tag t, void (T1::*f)(const T2*) )
			{
				// Creates a type-safe invoker to call f once the event comes here
				T1* downcastedThis = Reusable::checked_cast< T1* >( this ) ;
				TypeSafeInvoker< T1, T2 >* invoker = 
				new TypeSafeInvoker< T1, T2 >( downcastedThis, f ) ;
				// Add the invoker to the dispatching map of this sink
				const std::pair< const Tag, Invoker* > p( t, invoker ) ;
				dispMap.insert( p ) ;
				// subscribe the event from the source
				s.Subscribe( t, this ) ;
			}
			
			void UnsubscribeEvent(EventSource& s,Tag t);
			void HandleFirstEvent() ;
		
		private :
			EventQueue queue ;
			Reusable::CriticalSection guard ;
			typedef std::multimap< Tag, Invoker* > DispMap ;
			DispMap dispMap ;
			void HandleEvent( const Event* e ) ;
			void CleanupDispMap() ;
			bool RemoveDispMapElement(Tag t);
		} ;
	}
}

#endif