// CriticalSectionLock.h
#ifndef CRITICALSECTION_LOCK_


#define CRITICALSECTION_LOCK_

#include <windows.h>

namespace Reusable
{
	class CriticalSection ;

	class CriticalSectionLock
	{
	public :
		CriticalSectionLock( CriticalSection& s ) ;
		~CriticalSectionLock() ;
	private :
		CriticalSection& section ;
	} ;
}

#endif