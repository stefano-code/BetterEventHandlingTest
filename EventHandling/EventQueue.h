// EventQueue.h

#ifndef EVENTQUEUE_

#define EVENTQUEUE_

#pragma warning( disable: 4786 )

#include <queue>


namespace Technogym
{
	namespace EventHandling
	{
		class Event ;

		typedef std::queue< Event* > EventQueue ;
	}
}

#endif
