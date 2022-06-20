// SimpleEvent.cpp

#include "SimpleEvent.h"

using namespace EventHandling ;

SimpleEvent :: SimpleEvent( Tag t ) :
Event( t )
{
}

Event* SimpleEvent :: Clone() const
{
	return( new SimpleEvent( *this ) ) ;
}

std::string SimpleEvent :: SerializeOut() const
{
	std::string result ;
	return result ;
}

