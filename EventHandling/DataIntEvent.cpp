#include "stdafx.h"
#include "DataIntEvent.h"

using namespace Technogym::EventHandling ;

DataIntEvent :: DataIntEvent( Tag t,Value v ) :
Event(t)
{
	val = v ;
}

Value DataIntEvent :: GetValue() const
{
	return( val ) ;
}


Event* DataIntEvent :: Clone() const
{
	DataIntEvent* clone = new DataIntEvent( *this ) ;
	return( clone ) ;
}

std::string DataIntEvent :: SerializeOut() const
{
	std::string result ;
	char buf[ 10 ] ;
	sprintf( buf, "%d", val ) ;
	result += buf ;
	return result ;
}