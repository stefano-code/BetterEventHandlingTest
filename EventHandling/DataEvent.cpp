#include "stdafx.h"
#include "DataEvent.h"

using namespace Technogym::EventHandling ;

DataEvent :: DataEvent( Tag t,Value v ) :
Event(t)
{
	this->v = v ;
}

Value DataEvent :: GetValue() const
{
	return( v ) ;
}


Event* DataEvent :: Clone() const
{
	DataEvent* clone = new DataEvent( *this ) ;
	return( clone ) ;
}
