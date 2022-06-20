// CriticalSection.cpp

#include "CE_Assert.h" 
#include "CriticalSection.h"

using namespace Reusable ;

CriticalSection :: CriticalSection()
{
	InitializeCriticalSection( &s ) ;
}


CriticalSection :: ~CriticalSection()
{
	DeleteCriticalSection( &s ) ;
}


void CriticalSection :: Enter()
{
	EnterCriticalSection( &s ) ;
}


void CriticalSection :: Leave()
{
	LeaveCriticalSection( &s ) ;
}
