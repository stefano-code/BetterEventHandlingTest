// Event.cpp

#include <stddef.h>
#include "..\Reusable\CE_Assert.h" 
#include "Event.h"

using namespace Technogym::EventHandling ;

Event :: Event( Tag t ) : tag( t )
{
}
Event :: ~Event()
{
}
Tag Event :: GetTag() const
{
	return( tag ) ;
}
