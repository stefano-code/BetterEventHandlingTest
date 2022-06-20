// CriticalSection.h

#ifndef CRITICALSECTION_

#define CRITICALSECTION_

#include <windows.h>

namespace Reusable
{
	class CriticalSectionLock ;

	class CriticalSection
	{
	public :
		CriticalSection() ;
		~CriticalSection() ;
	private :
		void Enter() ;
		void Leave() ;
		CRITICAL_SECTION s ;
	friend class CriticalSectionLock ;
	} ;
}

#endif