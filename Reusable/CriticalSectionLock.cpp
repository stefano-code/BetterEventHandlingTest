// CriticalSectionLock.cpp

#include "CE_Assert.h" 
#include "CriticalSectionLock.h"
#include "CriticalSection.h"


using namespace Technogym::Reusable ;


CriticalSectionLock :: CriticalSectionLock( CriticalSection& s ) :
section( s)
{
	section.Enter() ;
}

CriticalSectionLock :: ~CriticalSectionLock()
{
	section.Leave() ;
}
